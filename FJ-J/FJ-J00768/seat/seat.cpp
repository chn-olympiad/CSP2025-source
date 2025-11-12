#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],p=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			p=i;
			break;
		}
	}
	int x=(p-1)/m+1,y=0;
	if(x%2==1){
		y=p-(x-1)*n;
	}else{
		y=n-(p-(x-1)*n)+1;
	}
	cout<<x<<" "<<y;
	return 0;
}



