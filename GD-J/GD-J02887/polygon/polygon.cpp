#include<bits/stdc++.h>
using namespace std;
int n,comp=0,way=0;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		comp=max(comp,a[i]);
	}
	if(n==3){
		int maxa=max(max(a[1],a[2]),a[3]);
		int sum=a[1]+a[2]+a[3];
		if(sum>2*maxa){
			cout<<1;
			return 0;
		}
	}else if(n==4){
		int suma=a[1]+a[2]+a[3];
		int sumb=a[1]+a[2]+a[4];
		int sumc=a[4]+a[2]+a[3];
		int sumd=a[4]+a[2]+a[3]+a[1];
		if(suma>comp*2)way++;
		if(sumb>comp*2)way++;
		if(sumc>comp*2)way++;
		if(sumd>comp*2)way++;
		cout<<way;
		return 0;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
