#include<bits/stdc++.h>
using namespace std;
int n,num,a[10000],sum;
int jojo(int q,int zh,int dz){
	if(dz*2<zh)	num++;
	for(int i=q;i<=n;i++){
		jojo(i+1,a[i]+zh,max(dz,a[i]));
	} 
	if(q==n)	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	jojo(1,0,0);
	cout<<num;
	return 0;
}
