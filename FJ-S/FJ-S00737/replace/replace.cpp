#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,ans;
bool f;
string s[N][3],t1,t2,t3;
bool check(int x,int y){
	for(int i=x;i<=x+s[y][1].size()-1;i++)
		if(t1[i]!=s[y][1][i-x])return 0;
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(int)t1.size()-(int)s[i][1].size();j++)
				if(check(j,i)){
					t3=t1;
					f=0;
					for(int k=j;k<=j+s[i][1].size()-1;k++)t3[k]=s[i][2][k-j];
					for(int k=0;k<t3.size();k++)
						if(t3[k]!=t2[k]){
							f=1;
							break;
						}
					if(!f)ans++;
				}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
