#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string a[N],b[N];
long long ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		string ta,tb;
		cin>>ta>>tb;
		ans=0;
		for(int i=1;i<=n;i++){
			string t=ta;
			int k=t.find(a[i]);
			int m=a[i].size();
			while(k!=-1){
				string x=t.substr(0,k),z=t.substr(m+k,t.size()-k-m);
				if(x+b[i]+z==tb){
					ans++;
					break;
				}
				k=t.find(a[i],k+1);
			}
		}
		cout<<ans;
	}
	return 0;
}
