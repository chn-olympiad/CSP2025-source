#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num,pai=1;
	cin>>n>>m;
	num=n*m;
	int a[105];
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int cj=a[1];
	for(int i=2;i<=num;i++){
		if(a[i]>cj){
			pai++;
		}
	}
	int shu=(pai-1)/n+1,heng;
	if(shu%2!=0){
		heng=pai-(shu-1)*n;
	}else{
		heng=n+1-(pai-(shu-1)*n);
	}
	cout<<shu<<' '<<heng;
} 