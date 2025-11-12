#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen ("seat.in","r",stdin);
freopen ("seat.out","w",stdout);
cin>>n>>m;
int len=n*m;
for (int i=0;i<len;i++){
	cin>>a[i];
}int R=a[0];
int bj=0;
sort(a,a+len,cmp);
for (int i=0;i<len;i++){
	if (a[i]==R){
		bj=i;
		break;
	}
}
int x=1,y=1,z=0;
for (int i=0;i<bj;i++){
	if (x%2==1){
		y++;
	}else if(x%2==0){
		y--;
	}if (y>n){
		x++;
		y=n;
}	if (y<1){
	x++;
	y=1;
}
}cout<<x<<" "<<y;
return 0;
}
