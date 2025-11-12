#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,q,nxt[N];
string s1[N],s2[N],t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int tt=1;tt<=n;tt++){
			string a=s1[tt],b=s2[tt];
			for(int i=0;i<t1.size();i++){
				bool f=true;
				for(int j=0;j<a.size();j++){
					if(t1[i+j]!=a[j]){
						f=false;
						break;
					}
				}
				if(f){
					string kkk=t1;
					for(int j=0;j<a.size();j++) kkk[i+j]=b[j];
					if(kkk==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

