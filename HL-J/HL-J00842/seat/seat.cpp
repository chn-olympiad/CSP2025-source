#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int x,int y){
	return (x>y);
}
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//n:ÐÐ£¬m:ÁÐ 
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int aa=a[1];
	sort(a+1,a+s+1,cmp);
	int wei;
	for(int i=1;i<=s;i++){
		if(aa==a[i]){
			wei=i;
			break;
		}
	}
	int hang=(wei-1)/n+1,lie;
	if(hang%2==1){
		lie=wei%n;
		if(lie==0){
			lie=n;
		}
	}
	else{
		int y=wei%n;
		if(y==0){
			y=n;
		}
		lie=n-y+1;
	}
	cout<<hang<<' '<<lie;
	return 0;
}
