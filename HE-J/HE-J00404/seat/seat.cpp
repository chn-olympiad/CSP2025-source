#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct info{
	int data,xb,x,y;
};
bool cmp(info v,info w){
	return v.data>w.data;
}
info a[110];
int n,m,cnt1=1,cnt2=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].xb=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].x=cnt1;
		a[i].y=cnt2;
		if((cnt1==n&&cnt2%2==1)||(cnt1==1&&cnt2%2==0)) cnt2++;
		else{
			if(cnt2%2==1) cnt1++;
			else if(cnt2%2==0) cnt1--;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].xb==1){
			cout<<a[i].y<<' '<<a[i].x;
			break;
		}
	}
	return 0;
}
