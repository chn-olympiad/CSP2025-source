#include<bits/stdc++.h>
using namespace std;
int mm=0,n;
struct f{
	int a,b,c;
}z[100010];
bool cmp(f x,f y){
	return x.a>y.a;
}
void dfs(int k1,int k2,int k3,int sum,int x){
	if(mm<sum)mm=sum;
	if(x==n)return;
	if(k1+1<=n/2)dfs(k1+1,k2,k3,sum+z[x].a,x+1);
	if(k2+1<=n/2)dfs(k1,k2+1,k3,sum+z[x].b,x+1);
	if(k3+1<=n/2)dfs(k1,k2,k3+1,sum+z[x].c,x+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		int f=1;
		for(int i=0;i<n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
			if(z[i].b!=0||z[i].c!=0)f=0;
		}
		if(f==1){
			sort(z,z+n,cmp);
			int sum=0;
			for(int i=0;i<n/2;i++)sum+=z[i].a;
			cout<<sum<<endl;
		}
		else{
			mm=0;
			dfs(0,0,0,0,0);
			cout<<mm<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
