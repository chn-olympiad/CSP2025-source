#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(;x<=m;x++){
		if(x%2){
			for(;y<=n;y++)
				if(a[(x-1)*n+y]==tmp){
					cout<<x<<" "<<y;
					return 0;
				}
		}
		else{
			for(;y>0;y--)
				if(a[(x-1)*n+n-y+1]==tmp){
					cout<<x<<" "<<y;
					return 0;
				}
		}
	}
	return 0;
}