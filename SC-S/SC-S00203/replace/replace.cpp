#include<bits/stdc++.h>
using namespace std;
int n,q;
struct ob{
	string t;
	string h;
}a[100001];
string x,y,z;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].h;
	}
	while(q--){
		string s,to;
		cin>>s>>to;
		int len=s.size();
		int ans=0;
		for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				x.clear();y.clear();z.clear();
				for(int k=0;k<i;k++)x+=s[k];
				for(int k=i;k<=j;k++)y+=s[k];
				for(int k=j+1;k<len;k++)z+=s[k];
				for(int i=1;i<=n;i++){
					if(y==a[i].t&&x+a[i].h+z==to){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}