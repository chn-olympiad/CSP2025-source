#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)

int n,m,nm,p,t;
int r,c;
int arr[105];

bool cmp(int &a,int &b){
	return a>b;
}

int main(){
	in("seat.in");
	out("seat.out");
	scanf("%d%d",&n,&m);
	nm = n*m;
	for(int i=1;i<=nm;i++)
		scanf("%d",&arr[i]);
	p = arr[1];
	sort(arr+1,arr+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if (arr[i] == p)	t = i;
	}
	t--;
	c = t/n+1;
	if (c&1){
		r = t%n+1;
	}else{
		r = n-t%n;
	}
	printf("%d %d",c,r);
	return 0;
}

