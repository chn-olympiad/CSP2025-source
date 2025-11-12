#include<bits/stdc++.h>
#define N 105
using namespace std;

int n,m;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int z=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k)z=i;
	}
	
	cout<<(z-1)/m+1<<" ";
	if((z/m)&1){
		if(!(n-(z%m)+1))cout<<n;
		else cout<<n-(z%m)+1;
	}else{
		if(!(z%m))cout<<n;
		else cout<<z%m;
	}
	return 0;
}

/*
2 2
99 100 97 98

1 2
*/

/*
3 3
94 95 96 97 98 99 100 93 92

3 1
*/

/*
4 4
10 1 2 3 4 5 6 7 8 9 11 12 13 14 15 16

2 2 
*/
