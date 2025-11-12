#include<bits/stdc++.h>
using namespace std;
int m,n,r,shu;
int h=1,l=1;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int kkk=m*n;
	sort(a+1,a+1+kkk);
	int zhuang=1;
	for(int i=kkk;i>=1;i--){
		if(a[i]==r){
			break;
		}
		if(i==kkk){
			zhuang=1;
		}
		if(zhuang==1&&h+1<=n){
			h++;
		}else if(zhuang==1&&h+1>n){
			l++;
			zhuang=0;
		}else if(zhuang==0&&h-1>=1){
			h--;
		}else if(zhuang==0&&h-1<1){
			l++;
			zhuang=1;
		}
	}
	cout<<l<<" "<<h;
	
	return 0;
}