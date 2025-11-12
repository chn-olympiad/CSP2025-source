#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 15
using namespace std;
int n,m,a[N*N],R,pos;
int c,l,lcnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			pos=i;
			break;
		}
	}
	c=(pos+n-1)/n;
	lcnt=pos-pos/n*n;
	if(!lcnt){
		if(c&1)
			l=n;
		else
			l=1;
	}else if(c&1)
		l=lcnt;
	else
		l=n-lcnt+1;
	cout<<c<<' '<<l;
	return 0;
}
