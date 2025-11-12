#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
struct node{int f,r};
int ss(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b'){
			return i;
		}
	}
}
node a[100005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		sting s1,s2;
		cin>>s1>>s2;
		int nu=ss(s1),mu=ss(s2);
		a[i]={nu,mu};
	}
	for(int i=1;i<=m;i++){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		int nu=ss(t1),mu=ss(t2);
		for(int i=1;i<=n;i++){
			{
				if(a[i].f-a[i].r==mu-nu) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
