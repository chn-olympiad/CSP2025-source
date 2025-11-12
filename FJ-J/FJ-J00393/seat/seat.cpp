#include<iostream>
#include<algorithm>
using namespace std;

int n,m,r;
int a[210],seat[20][20];

void shun(int l){
	for(int i=1;i<=n;i++)
		seat[i][l]=a[(l-1)*n+i];
}

void ni(int l){
	for(int i=1;i<=n;i++)
		seat[n-i+1][l]=a[(l-1)*n+i];
}

bool cmp(int a,int b){
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=m;i++){
		if(i%2) shun(i);
		else ni(i);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(seat[i][j]==r){
				cout<<j<<" "<<i<<endl;
				break;
			}
	
	return 0;
}
