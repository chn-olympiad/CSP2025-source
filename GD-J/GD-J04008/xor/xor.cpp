#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+6;
int n;
unsigned long long k;
int a[maxn];
int x[maxn]={0},y[maxn]={0};
int tans=0;
int yh(int x,int y){
	bool x1[30]={0},y1[30]={0};
	bool x2[30]={0},y2[30]={0};
	bool ans[30];
	int ansi=0;
	int wx=0,wy=0;
	for(int i=1;;i++){
		if(x==0&&y==0){
			break;
		}
		if(x==0){		
		}else if(x%2==0){
			x=x/2;
			x1[i]=0;
			wx++;
		}else{
			x=(x-1)/2;
			x1[i]=1;
			wx++;
		}
		if(y==0){
			continue;	
		}else if(y%2==0){
			y=y/2;
			y1[i]=0;
			wy++;
		}else{
			y=(y-1)/2;
			y1[i]=1;
			wy++;
		}
	}
	for(int i=1;i<29;i++){
		if(x1[i]==1||y1[i]==1){
			ans[i]=1;
		}else{
			ans[i]=0;
		}
	}
	for(int i=1;i<=max(wx,wy);i++){
		ansi+=ans[i]*pow(2,i-1);
	}
	return ansi;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(i,j)==k){
				for(int l=1;l<maxn;l++){
					if(x[l]==0){
						x[l]=i;
					} 
					if(y[l]==0){
						y[l]=j;
					} 
				}
			}
		}
	}
	for(int i=1;i<=1000;i++){
		int cnt=1,ny=y[i];
		for(int j=i;j<=1000;j++){
			if(ny<x[j]){
				cnt+=1;
				ny=y[j];
			}
			tans=max(cnt,tans);
		}
	}
	cout<<tans;
	return 0;
}
