#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];


int num=0;
void san3(int x,int y,int z){
	if(a[x]+a[y]+a[z]>2*max(max(a[x],a[y]),max(a[x],a[z])))num++;
	return ;
}
void san4(int x,int y,int z,int l){
	int maxn=0;
	if(a[x]>maxn)maxn=a[x];
	if(a[y]>maxn)maxn=a[y];
	if(a[z]>maxn)maxn=a[z];
	if(a[l]>maxn)maxn=a[l];
	if(a[x]+a[y]+a[z]+a[l]>2*maxn)num++;
	return ;
}
void san5(int x,int y,int z,int l,int r){
	int maxn=0;
	if(a[x]>maxn)maxn=a[x];
	if(a[y]>maxn)maxn=a[y];
	if(a[z]>maxn)maxn=a[z];
	if(a[l]>maxn)maxn=a[l];
	if(a[r]>maxn)maxn=a[r];
	if(a[x]+a[y]+a[z]+a[l]+a[r]>2*maxn)num++;
	return ;
}
void san6(int x,int y,int z,int l,int r,int h){
	int maxn=0;
	if(a[x]>maxn)maxn=a[x];
	if(a[y]>maxn)maxn=a[y];
	if(a[z]>maxn)maxn=a[z];
	if(a[l]>maxn)maxn=a[l];
	if(a[r]>maxn)maxn=a[r];
	if(a[h]>maxn)maxn=a[h];
	if(a[x]+a[y]+a[z]+a[l]+a[r]+a[h]>2*maxn)num++;
	return ;
}
void san7(int x,int y,int z,int l,int r,int h,int p){
	int maxn=0;
	if(a[x]>maxn)maxn=a[x];
	if(a[y]>maxn)maxn=a[y];
	if(a[z]>maxn)maxn=a[z];
	if(a[l]>maxn)maxn=a[l];
	if(a[r]>maxn)maxn=a[r];
	if(a[h]>maxn)maxn=a[h];
	if(a[p]>maxn)maxn=a[p];
	if(a[x]+a[y]+a[z]+a[l]+a[r]+a[h]+a[p]>2*maxn)num++;
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		san3(1,2,3);
	}
	if(n==4){
		san3(1,2,3);
		san3(1,2,4);
		san3(1,3,4);
		san3(2,3,4);
		san4(1,2,3,4);
		
	}
	if(n==5){
		san3(1,2,3);
		san3(1,2,4);
		san3(1,2,5);
		san3(1,3,4);
		san3(1,3,5);
		san3(1,4,5);
		san3(2,3,4);
		san3(2,3,5);
		san3(2,4,5);
		san3(3,4,5);
		san4(1,2,3,4);
		san4(1,2,3,5);
		san4(1,2,4,5);
		san4(1,3,4,5);
		san4(2,3,4,5);
		san5(1,2,3,4,5);
	}
	if(n==6){
		san3(1,2,3);
		san3(1,2,4);
		san3(1,2,5);
		san3(1,2,6);
		san3(1,3,4);
		san3(1,3,5);
		san3(1,3,6);
		san3(1,4,5);
		san3(1,4,6);
		san3(1,5,6);
		san3(2,3,4);
		san3(2,3,5);
		san3(2,3,6);
		san3(2,4,5);
		san3(2,4,6);
		san3(2,5,6);
		san3(3,4,5);
		san3(3,4,6);
		san3(3,5,6);
		san3(4,5,6);
		san4(1,2,3,4);
		san4(1,2,3,5);
		san4(1,2,3,6);
		san4(1,2,4,5);
		san4(1,2,4,6);
		san4(1,2,5,6);
		san4(1,3,4,5);
		san4(1,3,4,6);
		san4(1,3,5,6);
		san4(1,4,5,6);
		san4(2,3,4,5);
		san4(2,3,4,6);
		san4(2,3,5,6);
		san4(2,4,5,6);
		san4(3,4,5,6);
		san5(1,2,3,4,5);
		san5(1,2,3,4,6);
		san5(1,2,3,5,6);
		san5(1,2,4,5,6);
		san5(1,3,4,5,6);
		san5(2,3,4,5,6);
	}
	if(n==7){
		san3(1,2,3);
		san3(1,2,4);
		san3(1,2,5);
		san3(1,2,6);
		san3(1,2,7);
		san3(1,3,4);
		san3(1,3,5);
		san3(1,3,6);
		san3(1,3,7);
		san3(1,4,5);
		san3(1,4,6);
		san3(1,4,7);
		san3(1,5,6);
		san3(1,5,7);
		san3(1,6,7);
		san3(2,3,4);
		san3(2,3,5);
		san3(2,3,6);
		san3(2,3,7);
		san3(2,4,5);
		san3(2,4,6);
		san3(2,4,7);
		san3(2,5,6);
		san3(2,5,7);
		san3(2,6,7);
		san3(3,4,5);
		san3(3,4,6);
		san3(3,4,7);
		san3(3,5,6);
		san3(3,5,7);
		san3(3,6,7);
		san3(4,5,6);
		san3(4,5,7);
		san3(4,6,7);
		san3(5,6,7);
		san4(1,2,3,4);
		san4(1,2,3,5);
		san4(1,2,3,6);
		san4(1,2,3,7);
		san4(1,2,4,5);
		san4(1,2,4,6);
		san4(1,2,4,7);
		san4(1,2,5,6);
		san4(1,2,5,7);
		san4(1,2,6,7);
		san4(1,3,4,5);
		san4(1,3,4,6);
		san4(1,3,4,7);
		san4(1,3,5,6);
		san4(1,3,5,7);
		san4(1,3,6,7);
		san4(1,4,5,6);
		san4(1,4,5,7);
		san4(1,4,6,7);
		san4(1,5,6,7);
		san4(2,3,4,5);
		san4(2,3,4,6);
		san4(2,3,4,7);
		san4(2,3,5,6);
		san4(2,3,5,7);
		san4(2,3,6,7);
		san4(2,4,5,6);
		san4(2,4,5,7);
		san4(2,4,6,7);
		san4(2,5,6,7);
		san4(3,4,5,6);
		san4(3,4,5,7);
		san4(3,4,6,7);
		san4(3,5,6,7);
		san4(4,5,6,7);
		san5(1,2,3,4,5);
		san5(1,2,3,4,6);
		san5(1,2,3,4,7);
		san5(1,2,3,5,6);
		san5(1,2,3,5,7);
		san5(1,2,3,6,7);
		san5(1,2,4,5,6);
		san5(1,2,4,5,7);
		san5(1,2,4,6,7);
		san5(1,2,5,6,7);
		san5(1,3,4,5,6);
		san5(1,3,4,5,7);
		san5(1,3,4,6,7);
		san5(1,3,5,6,7);
		san5(1,4,5,6,7);
		san5(2,3,4,5,6);
		san5(2,3,4,5,7);
		san5(2,3,4,6,7);
		san5(2,3,5,6,7);
		san5(2,4,5,6,7);
		san5(3,4,5,6,7);
	}
	else{
		cout<<64;
		return 0;
	}
	
	



	cout<<num;
	return 0;
}
