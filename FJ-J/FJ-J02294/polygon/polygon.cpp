#include<bits/stdc++.h>
using namespace std; 
int n,ans;
int a[5010];
bool f[5010];
void fd(int z,int t,int ma,int sum){
	if(t==z){
		if(ma*2<sum) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			if(a[i]>ma) fd(z,t+1,a[i],sum+a[i]);
			else fd(z,t+1,ma,sum+a[i]);
			f[i]=false;
			
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a[i]);
	for(int i=3;i<=n;i++){
		fd(i,0,0,0);
	}
	cout<<ans;
	return 0; 
} 
/*
5
2 2 3 8 10

*/
