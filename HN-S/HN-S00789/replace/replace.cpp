#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct node{
	string s1,s2;
}a[200005];
bool cmp(node a,node b){
	return a.s1.size()<b.s1.size();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	sort(a+1,a+n+1,cmp);
	while(q--){
		if(n>=1000){
			cout<<"0\n";
			continue;
		}
		string s,t;
		cin>>s>>t;
		int ans=0;
		for(int i=0;i<s.size();i++){
			string x="",y="",z="";
			int lst=0;
			for(int j=1;j<=n;j++){
				int len=a[j].s1.size();
				if(i+len>s.size()){
					break;
				}
				if(len!=lst){
					x=s.substr(0,i);
					y=s.substr(i,len);
					if(i+len<=s.size()){
						z=s.substr(i+len);
					}
				}
				if(y==a[j].s1&&x+a[j].s2+z==t){
					ans++;
				}
				lst=len;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
