#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		num=1;
	}
	if(n==4){
		sort(a,a+n+1,cmp);
		if(a[0]+a[1]+a[2]>a[0]*2){
			num++;
		}
		if(a[0]+a[1]+a[3]>a[0]*2){
			num++;
		}
		if(a[0]+a[2]+a[3]>a[0]*2){
			num++;
		}
		if(a[1]+a[2]+a[3]>a[1]*2){
			num++;
		}
		if(a[0]+a[1]+a[2]+a[3]>a[0]*2){
			num++;
		}
	}
	if(n==5){
		sort(a,a+n+1,cmp);
		if(a[0]+a[1]+a[2]>a[0]*2){
			num++;
		}
		if(a[0]+a[1]+a[3]>a[0]*2){
			num++;
		}
		if(a[0]+a[1]+a[4]>a[0]*2){
			num++;
		}
		if(a[0]+a[2]+a[3]>a[0]*2){
			num++;
		}
		if(a[0]+a[2]+a[4]>a[0]*2){
			num++;
		}
		if(a[0]+a[3]+a[4]>a[0]*2){
			num++;
		}
		if(a[1]+a[2]+a[3]>a[1]*2){
			num++;
		}
		if(a[1]+a[2]+a[4]>a[1]*2){
			num++;
		}
		if(a[1]+a[3]+a[4]>a[1]*2){
			num++;
		}
		if(a[2]+a[3]+a[4]>a[2]*2){
			num++;
		}
		if(a[0]+a[1]+a[2]+a[3]>a[0]*2){
			num++;
		}
		if(a[0]+a[1]+a[2]+a[4]>a[0]*2){
			num++;
		}
		if(a[0]+a[1]+a[3]+a[4]>a[0]*2){
			num++;
		}
		if(a[0]+a[2]+a[3]+a[4]>a[0]*2){
			num++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[1]*2){
			num++;
		}
		if(a[0]+a[1]+a[2]+a[3]+a[4]>a[0]*2){
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
