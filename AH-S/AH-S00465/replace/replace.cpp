#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long 
pair<string,string> a[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i].first=s1;
		a[i].second=s2;
	}
	for(int i=1;i<=q;i++){
		string sx,sy;
		ll sum=0;
		cin>>sx>>sy;
		for(int j=1;j<=n;j++){
			for(ull k=0;k<sx.size()-a[j].first.size()+1;k++){
				if(sx.substr(k,a[j].first.size())==a[j].first){
					string sk=sx;
					sk.replace(k,a[j].first.size(),a[j].second);
					if(sk==sy)sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
