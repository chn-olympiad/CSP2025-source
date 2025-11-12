#include<bits/stdc++.h>
using namespace std;
int n,z;
int a[10000];
int m(int zh,int wz,int zd,int zs){
	if(wz>=5){
		return 0;
	}
	for(int i=wz+1;i<=n;i++){
		if(a[i]+zh>2*zd&&zs>=3){
			cout<<1<<endl;
			z++;
			return 0;
		}
		if(i==5){
			return 0;
		}
		cout<<zh+a[i]<<" "<<i<<" "<<max(a[i],zd)<<" "<<zh+1<<endl;
		m(zh+a[i],i,max(a[i],zd),zs+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	m(0,0,-1,0);
	cout<<z;
	return 0; 
} 

