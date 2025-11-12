#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,x,st;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			st=i;
			break;
		}
	}
	int ansn,ansm;
	//将n*2个人分为一组
	//cout<<st<<" "<<st%(n*2)<<endl; 
	if(st%(n*2)>n){
		//在偶数列 
		ansn=n+1-((st%(n*2))-n);
		ansm=st/(n*2)*2+2;
		//cout<<1;
	}
	if(st%(n*2)>=1&&st%(n*2)<=n){
		//在奇数列 
		ansn=st%(n*2);
		ansm=st/(n*2)*2+1;
		//cout<<2; 
	} 
	if(st%(n*2)==0){
		//这一组最后一个 
		ansn=1;
		ansm=st/(n*2)*2;
		//cout<<3;
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}
