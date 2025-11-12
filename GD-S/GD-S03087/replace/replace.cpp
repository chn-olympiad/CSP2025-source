#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f;
int n,q;
string s1[N],s2[N],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n<=100&&q<=100){
		while(q--){
			cin>>t1>>t2;
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=t1.size();j++){
					int fl=0;
					string ss=t1;
					for(int j1=j;j1<j+s1[i].size();j1++){
						if(ss[j1]!=s1[i][j1-j]){
							fl=1;
						}
					}if(fl==0){
						for(int j1=j;j1<j+s1[i].size();j1++){
							ss[j1]=s2[i][j1-j];
						}
					}
	//				cout<<ss<<endl;
					if(ss==t2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(q--){
			cin>>t1>>t2;
			cout<<0<<endl;
		}
	}
	return 0;
}

