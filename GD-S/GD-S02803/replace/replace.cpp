#include<bits/stdc++.h>
//#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,ans,p[5200005],l[N],op[N];
int u[N],cl[N],cr[N];
string s1[N],s2[N],t1,t2;
bool sp=1;
int fib(string st){
	for(int i=1;i<(int)st.size();i++)
		if(st[i]=='b')
			return i;
	return 0;
}
void solve2(){
	for(int i=1;i<=n;i++){
		cl[i]=fib(s1[i])-1;
//		cout<<1;
		cr[i]=(int)s1[i].size()-cl[i]-1;
		u[i]=fib(s2[i])-cl[i]-1;
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		t1=" "+t1;
		t2=" "+t2;
		int l1=t1.size()-1,l2=t2.size()-1;
		if(l1!=l2){
			cout<<0<<"\n";
			continue;
		}
		int k1=fib(t1),k2=fib(t2);
		for(int i=1;i<=n;i++)
			if(u[i]==k2-k1&&k1-1>=cl[i]&&l1-k1>=cr[i])
				ans++;
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		l[i]=l[i-1]+s1[i].size();
	}
	for(int i=1;i<=n;i++){
		int g=0;
		for(int j=1;j<=(int)s1[i].size()-1;j++){
			if(s1[i][j]!='a'){
				if(s1[i][j]!='b'||(s1[i][j]=='b'&&g==1)){
					g=2;
					break;
				}
				else
					g++;
			}
		}
		if(g==2){
			sp=0;
			break;
		}
		g=0;
		for(int j=1;j<=(int)s2[i].size()-1;j++){
			if(s2[i][j]!='a'){
				if(s2[i][j]!='b'||(s2[i][j]=='b'&&g==1)){
					g=2;
					break;
				}
				else
					g++;
			}
		}
		if(g==2){
			sp=0;
			break;
		}
	}
	if(sp){
		solve2();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int gu=l[i-1]+1;
//		cout<<gu<<" "<<ga<<"\n";
		int k=0;
		p[gu]=0;
		for(int j=2;j<=l[i]-l[i-1];j++){
			while(p[k+gu]&&s1[i][k+1]!=s1[i][j])
				k=p[k+gu];
			if(s1[i][k+1]==s1[i][j])
				k++;
			p[gu+j]=k;
		}
	}
//	for(int i=1;i<=l[n];i++)
//		cout<<p[i]<<' ';
	while(q--){
		cin>>t1>>t2;
		ans=0;
		t1=" "+t1;
		t2=" "+t2;
		int l1=t1.size()-1,l2=t2.size()-1;
		if(l1!=l2){
			cout<<0<<"\n";
			continue;
		}
		int kl=1e9,kr=0;
		for(int i=1;i<=l1;i++){
			if(t1[i]!=t2[i]){
				kl=min(kl,i);
				kr=max(kr,i);
			}
		}
		memset(op,0,sizeof(op));
		int ans=0;
		for(int i=1;i<=l1;i++){
			for(int j=1;j<=n;j++){
				int ls=l[j]-l[j-1]-1;
				if(ls<kr-kl+1)
					continue;
				int gu=l[j-1]+1;
				while(p[op[j]+gu]&&t1[i]!=s1[j][op[j]+1])
					op[j]=p[op[j]+gu];
				if(t1[i]==s1[j][op[j]+1])
					op[j]++;
				if(op[j]==ls){
					int ll=i-ls+1,rr=i;
//					cout<<j<<' '<<ll<<' '<<rr<<"\n";
					if(ll<=kl&&kr<=rr){
						bool flag=1;
						for(int k=1;k<=ls;k++){
							if(t2[ll+k-1]!=s2[j][k]){
								flag=0;
								break;
							}
						}
						if(flag)
							ans++;
					}
					op[j]=p[op[j]+gu];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

