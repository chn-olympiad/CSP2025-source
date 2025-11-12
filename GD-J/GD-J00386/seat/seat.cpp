#include <iostream>
#include <algorithm>
using namespace std;

int n,m,s,f;
int a[111];

bool cmp(int a,int b){
	return a>b;
}

void dfs(int z,int x,int y,int q){
//	cout<<x<<" "<<y<<" "<<z<<endl;
	if(z==0){
		cout<<x<<" "<<y;
		return;
	}
	if(y==n&&q==1)x++,q=-1;//±ﬂΩÁ1 
	else if(y==1&&q==-1)x++,q=1;//±ﬂΩÁ2 
	else y+=q;
	dfs(z-1,x,y,q);
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	f=a[1];//¥Ê¥¢a[1]
	for(int i=2;i<=n*m;i++){//2~n*m
		cin>>a[i];
	} 
	sort(a+1,a+n*m+1,cmp);//≈≈–Ú 
	for(int i=1;i<=n*m;i++){//≤È—Ø 
		if(a[i]==f){
			s=i;break;
		}
	}
	dfs(s-1,1,1,1);//±©¡¶—∞’“ 
	return 0;
} 
/*
2 10
1 2 3 4 5 6 7 8 9 0 11 22 33 44 55 66 77 88 99 90
*/
