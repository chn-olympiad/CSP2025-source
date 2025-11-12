#include<bits/stdc++.h>
using namespace std;
#define P9
#ifdef P9
	inline void su(){freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);}
#endif

int a[1145];
bool cmp(const int& a,const int& b){
	return a>b;
}
int main(){
	su();
	int n,m;
	int b;
	cin>>m>>n;
	b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int r1=a[1],k;
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=b;i++){
		if(a[i]==r1)k=i;
	}
	int c=(k-1)/n+1,r=k%n;
	if(!r)r=n;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}

