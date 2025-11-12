#include<bits/stdc++.h>
using namespace std;
long long z,x,c,v,b;
int ans;
long long mod=998244353;
long long a[5000],ab[5000];
bool ccc[5001];
void dfs(int zz,int xx,long long cc,int ooo){
if(cc>xx&&ooo>=2){
ans=(ans+1)%998244353;
}
int y=0;
for(int i=zz-1;i>=0;i--)
{	dfs(i,xx,cc+a[i],ooo+1);
} }
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>z;
for(int i=0;i<z;i++){
	cin>>a[i];}
sort(a,a+z);
for(int i=0;i<z-1;i++){
	x=x+a[i];
	if(x<a[i+1]){
		ccc[i+1]=1;
	}
	}
if(x<a[z-1]||z<3){
	cout<<-1;
	return 0;}
int o=0;
for(int i=2;i<z;i++){
	if(ccc[i]==0)
	dfs(i,a[i],0,0);
	}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
} 
