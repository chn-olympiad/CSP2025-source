#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string s,t;
}a[N],b[N];
struct node2{
	int l,len,powerup;
}num[N];
bool spc(string ss){
	int cnt=0;
	for(int i=0;i<ss.size();i++){
		if(ss[i]=='b') cnt++;
		else if(ss[i]!='a') return 1; 
	}
	if(cnt!=1) return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].t;
	for(int i=1;i<=q;i++){
		cin>>b[i].s>>b[i].t;
	}
	bool f=0;
	for(int i=1;i<=n;i++) if(spc(a[i].s)||spc(a[i].t)) f=1;
	for(int i=1;i<=q;i++) if(spc(b[i].s)||spc(b[i].t)) f=1;
	if(!f){
		for(int i=1;i<=n;i++){
			int pos1,pos2;
			for(int j=0;j<a[i].t.size();j++){
				if(a[i].s[j]=='b') pos1=j;
				if(a[i].t[j]=='b') pos2=j;
			}
			num[i].len=a[i].s.size(),num[i].l=pos1,num[i].powerup=pos2-pos1;
		}
		for(int i=1;i<=q;i++){
			int pos1,pos2,ans=0;
			for(int j=0;j<b[i].s.size();j++){
				if(b[i].s[j]=='b') pos1=j;
				if(b[i].t[j]=='b') pos2=j;
			}
			for(int j=1;j<=n;j++){
				if(pos2-pos1==num[j].powerup){
					if(pos1>=num[j].l&&b[i].s.size()-1-pos1>=num[j].len-num[j].l-1) ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			string ss1=a[j].s,ss2=b[i].s;
			int ll=a[j].s.size(),ll2=b[i].s.size();
			if(ll2<ll) continue;
			for(int k=0;k<ll2-ll+1;k++){
				ss1=a[j].s,ss2=b[i].s;
				bool ff=1;
				for(int g=k;g<k+ll;g++){
					if(ss2[g]!=ss1[g-k]){
						ff=0;
						break;
					}
				}
				//cout<<ss2<<" "<<ss1<<endl;
				if(ff){
					for(int g=k;g<k+ll;g++){ 
						ss2[g]=a[j].t[g-k];
					}
					if(ss2==b[i].t) ans++;
					//cout<<ss2<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
