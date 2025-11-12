#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string a[200005],b[200005],c,d;
bool check(string x,string y,string z){
	if(x.find(z)==-1){
		return 0;
	}
	if(x.size()!=y.size()){
		return 0;
	}
	for(int i=0;i<x.find(z);i++){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	for(int i=x.find(z)+z.size();i<x.size();i++){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		ans=0;
		cin>>c>>d;
		for(int j=1;j<=n;j++){
//			cout<<check(c,d,a[j])<<endl;
			if((check(c,d,a[j])||check(c,d,b[j]))&&c.find(a[j])==d.find(b[j])&&c.find(a[j])!=-1){
				ans++;	
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
