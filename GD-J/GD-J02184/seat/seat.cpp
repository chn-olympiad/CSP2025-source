#include<algorithm>
#include<iostream>
using namespace std;
int n,m,s;
struct student{
	int f,y;
}a[10010];
bool cmp(student x,student y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].y=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s++;
				if(a[s].y==1) { cout<<i<<" "<<j; return 0;}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s++;
				if(a[s].y==1) { cout<<i<<" "<<j; return 0;}
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
