#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],fw,xm,num,l=1,h,sy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+num+1,greater<int>());
	for(int i=1;i<=num;i++){
		if(a[i]==xm){
			fw=i;
			break;
		}
	}
	int gfw=fw;
	while(1){
		if(gfw-n>0){
			gfw-=n;
			l++;
		}else{
			break;
		}
	}
	if(l%2!=0){
		h=gfw;
	}else{
		h=n-gfw+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

