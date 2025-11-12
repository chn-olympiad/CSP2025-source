#include<iostream>
#include<cstdio>
using namespace std;
long long s,u=0,m=0,k=1,h=1,i=1;
int a[1000010]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(u=s;u>1;m++){
		u=u/10;
	}
	for(i=1;i<=m;i++){
		a[i]=s/k;
		a[i]=a[i]%10;
		k=k*10;
	}
	for(int y=1;y<=m;y++){
		for(h=1;h<=m-y;h++){
			if(a[y]<=a[y+h]){
				a[y]=a[y]+a[y+h];
				a[y+h]=a[y]-a[y+h];
				a[y]=a[y]-a[y+h];
			}
		}
	}
	for(int t=1;t<=m;t++) cout<<a[t];
	return 0;
}
