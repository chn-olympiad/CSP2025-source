#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
int n,m,ans;
struct str{
	string y,y1;
}s[N];
string s1,s2,x,z;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i].y>>s[i].y1;
	}
	for(int i=0;i<m;i++){
		ans=0;
		cin>>s1>>s2;
		for(int j=0;j<n;j++){
			if(s[j].y==s1&&s[j].y1==s2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
