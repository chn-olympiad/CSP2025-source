#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define pt array<string,2>
const int N=2e5+10;
int n,q;
pt s[N];
map<string,string>mp;
map<string,int>p,dp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	F(i,1,n)cin>>s[i][0]>>s[i][1],mp[s[i][0]]=s[i][1],p[s[i][0]]++,dp[s[i][0]]=p[s[i][0]];
	for(string x,y;q--;){
		int ans=0;
		cin>>x>>y;
		F(i,0,x.size()-1){
			for(int j=1;i+j<=x.size();j++){
				string t1=x.substr(0,i),t2=x.substr(i,j),t3=x.substr(i+j);
//				cout<<t1<<" "<<t2<<" "<<t3<<"\n";
				string p1,p2,p3;
				for(int k=0;k<(1<<3)-1;k++){
//					cout<<mp.count(t1)<<" "<<mp.count(t2)<<" "<<mp.count(t3)<<"\n";
					
					if(k&&mp.count(t1)&&p[t1]>0)p1=mp[t1],p[t1]--;
					else p1=t1;
					if((k>>1)&&mp.count(t2)&&p[t2]>0)p2=mp[t2],p[t2]--;
					else p2=t2;
					if((k>>2)&&mp.count(t3)&&p[t3]>0)p3=mp[t3],p[t3]--;
					else p3=t3;
					string tmp=p1+p2+p3;
//					cout<<tmp<<"\n";
					if(tmp==y){
						ans++;
						p[t1]=dp[t1];
						p[t2]=dp[t2];
						p[t3]=dp[t3];
						break;
					}
				}
				
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
