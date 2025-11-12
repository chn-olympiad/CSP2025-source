#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,num,ans=0,i=1,j=1,l;
int Xor(int o,int p){
	int y[50],u[50],nu[51],an=0,yl=0,ul=0,h=1;
	for(int b=1;b<=50;b++)nu[b]=0;
	bool s=0;
	while(o!=0){
		yl++;
		y[yl]=o%2;
		o/=2;
	}
	while(p!=0){
		ul++;
		u[ul]=p%2;
		p/=2;
	}
	for(int b=1;b<=max(yl,ul);b++){
		if(y[b]!=u[b]){
			nu[b]=1;
			s=1;	
		}
	}
	if(s==1){
		for(int b=1;b<=max(yl,ul);b++){
			an+=nu[b]*h;
			h*=2;
		}
		return an;
	}
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int b=1;b<=n;b++)scanf("%d",&a[b]);
	num=a[1];
	while(i<n||j<n){
		if(num==k){
			ans+=1;
			j++;
			i=j;
			num=a[i];
		}
		while(num<k&&j<n){
			j++;
			l=a[i];
			for(int k=i+1;k<=j;k++){
				l=Xor(l,a[k]);
				num=l;
			}
		}
		if(num>k){
			i++;
			j=i;
			num=a[i];
		}
		if(num<k){
			i=j;
			num=a[i];
		}
	}
	cout<<ans;
	return 0;
}
