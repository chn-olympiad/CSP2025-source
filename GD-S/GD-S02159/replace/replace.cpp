#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
string s1[N],s2[N];
string q1,q2;
int bo=0;
int check(int x,int p){
	if(x+s1[p].size()-1<bo)return 0;
	for(int i=x;i<=x+s1[p].size()-1;i++){
		if(s1[p][i-x]!=q1[i]){
			return 0;
		}
		if(s2[p][i-x]!=q2[i])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(m--){
		int ans=0;
		cin>>q1>>q2;
		for(int i=q1.size()-1;i>=0;i--){
			if(q1[i]!=q2[i]){
				bo=i;
				break;
			}
		}
		for(int i=0;i<q1.size();i++){
			if(i>0&&q1[i-1]!=q2[i-1])break;
			for(int j=1;j<=n;j++){
				ans+=check(i,j);
			//	if(check(i,j))cout<<i<<" "<<j<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
