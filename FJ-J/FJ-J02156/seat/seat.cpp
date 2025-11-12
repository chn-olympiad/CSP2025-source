#include<bits/stdc++.h>
using namespace std;
struct Seg{
	int num,x,y;
};
const int N=210;
Seg a[N];
bool cmp(Seg a,Seg b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
	}
	int pos=a[1].num;
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=1,flag=-1;
	for(int i=1;i<=n*m;i++){
		a[i].x=nx;
		a[i].y=ny;
		if(i%n==0){
			flag*=-1;
			ny++; 
			continue;
		}
		if(flag==-1){
			nx++;
		}else if(flag==1){
			nx--;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].num==pos){
			cout<<a[i].y<<" "<<a[i].x;
			return 0;
		}
	}
	return 0;
}
