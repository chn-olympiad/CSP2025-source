#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct zx{
	int a;
	int b;
	int c;
	int xb;
}arr[100001];
bool cmp(zx x,zx y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;
		}
		else{
			return x.b>y.b;
		}
	}
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>arr[j].a>>arr[j].b>>arr[j].c;
			arr[j].xb=j;	
		}
		sort(arr+1,arr+1+n,cmp);
		for(int j=1;j<=n/2;j++){
			ans+=arr[j].a;
		}
		for(int j=n/2;j<=n;j++){
			ans+=arr[j].b;
		}
		cout<<ans<<endl;
		for(int j=1;j<n;j++){
			arr[j].a=0;
			arr[j].b=0;
			arr[j].c=0;
			arr[j].xb=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
