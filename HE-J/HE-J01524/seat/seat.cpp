/*
奇数往下走，偶数往上走 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],cnt,x,p;
int ansn,ansm;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;++i)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;++i)
		if(a[i]==x)p=i;
	ansm=(p-1)/n+1;
	int t=(p-1)%n+1;
	if(ansm&1)ansn=t;
	else ansn=n-t+1;
	cout<<ansm<<" "<<ansn; 
	return 0;
}
/*
2 2 
99 100 97 98

2 2 
98 99 100 97
*/
