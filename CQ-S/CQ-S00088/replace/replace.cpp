#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=5e6+10;
const ll base=131,mod=1e9+7;
int n,q;
ll ans=0;
int len1[N],len2[N];
string s1[N],s2[N],t1,t2;
vector<ll> nex1[N],record1[N],record2[N];
int val[N][2];
ll pw[M],Hash1[M],Hash2[M];
int get1(int l,int r){
	if(l>r) return 0;
	int len=r-l+1;
	return (Hash1[r]-pw[len]*Hash1[l-1]%mod+mod)%mod;
}
int get2(int l,int r){
	if(l>r) return 0;
	int len=r-l+1;
	return (Hash2[r]-pw[len]*Hash2[l-1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base%mod;
	Hash1[0]=Hash2[0]=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len1[i]=s1[i].size();
		len2[i]=s2[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		nex1[i].resize(len1[i]+1);
		record1[i].resize(len1[i]+1);
		record2[i].resize(len2[i]+1);
		for(int j=1;j<=len1[i];j++) record1[i][j]=(record1[i][j-1]*base+s1[i][j]-'a'+1)%mod;
		for(int j=1;j<=len2[i];j++) record2[i][j]=(record2[i][j-1]*base+s2[i][j]-'a'+1)%mod;
		val[i][0]=record1[i][len1[i]];
		val[i][1]=record2[i][len2[i]];
//		cout<<val[i][0]<<" "<<val[i][1]<<"\n";
		
		int k=0;
		nex1[i][1]=0;
		for(int j=1;j<len1[i];j++){
			while(k&&s1[i][j+1]!=s1[i][k+1]) k=nex1[i][k];
			if(s1[i][j+1]==s1[i][k+1]) k++;
			nex1[i][j+1]=k;
		}
//		for(int j=1;j<=len1[i];j++) cout<<nex1[i][j]<<" ";
//		cout<<"\n";
	}
	if(q==1||n>=1000){
		while(q--){
			ans=0;
			cin>>t1>>t2;
			int m1=t1.size(),m2=t2.size();
			t1=" "+t1,t2=" "+t2;
			for(int i=1;i<=m1;i++) Hash1[i]=(Hash1[i-1]*base+t1[i]-'a'+1)%mod;
			for(int i=1;i<=m2;i++) Hash2[i]=(Hash2[i-1]*base+t2[i]-'a'+1)%mod;
			int l=1,r=min(m1,m2),pos=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(Hash1[mid]!=Hash2[mid]) pos=mid,r=mid-1;
				else l=mid+1;
			}
	//		cout<<pos<<"\n";
			for(int i=1;i<=n;i++){
				for(int j=len1[i];j>=1;j--){
					if(pos-j+1<=0) continue;
					if(record1[i][j]==get1(pos-j+1,pos)){
						int now=j;
						while(now){
							int l=pos-now+1,r=l+len1[i]-1;
							if(val[i][0]==get1(l,r)){
	//							cout<<i<<" "<<l<<"\n";
								ll tmp1=Hash1[l-1]*pw[m1-l+1]%mod,tmp2=val[i][1]*pw[m1-r]%mod,tmp3=get1(r+1,m1);
								if((tmp1+tmp2+tmp3)%mod==Hash2[m2]) ans++;
							}
							now=nex1[i][now];
						}
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(n<=1000){
		while(q--){
			ans=0;
			cin>>t1>>t2;
			int m1=t1.size(),m2=t2.size();
			t1=" "+t1,t2=" "+t2;
			for(int i=1;i<=m1;i++) Hash1[i]=(Hash1[i-1]*base+t1[i]-'a'+1)%mod;
			for(int i=1;i<=m2;i++) Hash2[i]=(Hash2[i-1]*base+t2[i]-'a'+1)%mod;
			for(int i=1;i<=m1;i++){
				for(int j=1;j<=n;j++){
					if(i+len1[j]-1>m1||i+len2[j]-1>m2) continue;
					int r=i+len1[j]-1;
					if(val[j][0]==get1(i,i+len1[j]-1)){
//						cout<<i<<" "<<j<<"\n";
						ll tmp1=Hash1[i-1]*pw[m1-i+1]%mod,tmp2=val[j][1]*pw[m1-r]%mod,tmp3=get1(r+1,m1);
//						cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<"\n";
						if((tmp1+tmp2+tmp3)%mod==Hash2[m2]) ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
