#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
int n,m,wei,lie,row;
struct node{
	int mack;
	bool op;
}student[N*N];
bool cmp(node x,node y){
	return x.mack>y.mack;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>student[i].mack;
		if(i==1) student[i].op=1;
		else student[i].op=0;
	}
	sort(student+1,student+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) {
		if(student[i].op ) {
			wei=i;
			break;
		}
	}
	lie=(wei+n-1)/n;
	row=(wei-1)%(2*n)+1;
	if(row>n){
		row-=n;
		row=n-row+1;
	} 
	printf("%lld %lld",lie,row);
	return 0;
}

