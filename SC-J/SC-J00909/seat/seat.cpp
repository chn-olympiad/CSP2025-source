#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[110],k,pos;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k)pos=i;
	}
	
	cout<<(pos+n-1)/n<<" ";
	if((pos+n-1)/n%2==1)cout<<pos-((pos+n-1)/n-1)*n;
	else cout<<n+1-(pos-((pos+n-1)/n-1)*n);
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
/*
4 4
9 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16
*/