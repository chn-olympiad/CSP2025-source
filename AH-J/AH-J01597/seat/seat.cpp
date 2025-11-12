#include<bits/stdc++.h>
using namespace std;
const int N=129;
int a[129];
bool cmp(int m,int n){
	return m>n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++)
		cin>>a[i];
	int r=a[1],w;
	sort(a+1,a+1+z,cmp);
	for(int i=1;i<=z;i++){
		if(a[i]==r){
			w=i;
			break;
		}
	}
	int T=n*2;
	int sh=w/T,yu=w%T;
	int yl=sh*2+1,yh;
	if(yu>n){
		yl++;
		yh=T-yu+1;
	}else
		yh=yu;
	cout<<yl<<" "<<yh;
	return 0;
}

