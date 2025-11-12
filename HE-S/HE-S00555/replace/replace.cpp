#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string s1[N],s2[N];
string t1,t2;
int n,q;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			string s,ss;
			s=t1,ss=t2;
			int ops=0;
			while(ops<t1.size()){
				if(t1.find(s1[j],ops)==-1) break;
				else{
					ops=t1.find(s1[j],ops);
					for(int t=ops;t<ops+s2[j].size();t++){
						s[t]=s2[j][t-ops];
					}
					if(s==ss) {
						ans++;
						break;
					}
					else s=t1;
					ops++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
