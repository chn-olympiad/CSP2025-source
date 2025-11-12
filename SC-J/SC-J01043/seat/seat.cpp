#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,sc,num,ansn,ansm;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			num=i;
			break;
		}
	}
	ansm=num/(2*n)*2;
	num%=(2*n);
	if(num==0){
		ansn=1;
	}
	else if(num>n){
		ansm+=2;
		num-=n;
		ansn=n-num+1;
	}
	else{
		ansm++;
		ansn=num;
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}
