#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],num,x;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>num;
	a[1]=num;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			x=i;
			break;
		}
	}
	cout<<(x-1)/n+1<<' '<<(((x-1)/n+1)%2==0?n-(x-1)%n:(x-1)%n+1);
	return 0;
}
