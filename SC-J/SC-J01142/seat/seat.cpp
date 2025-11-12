#include<cstdio> 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[128];
int n,m;
int z,x;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	z = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			x=i;
			break;
		}
	}
	int ansx=1,ansy=1;
	bool flag = 1;
	for(int i=1;i<x;i++){
		if(ansy==n&&flag)ansx++,flag=0;
		else if(ansy==1&&!flag)ansx++,flag=1;
		else if(flag)ansy++;
		else ansy--;
	}
	printf("%d %d",ansx,ansy);
	return 0;
}