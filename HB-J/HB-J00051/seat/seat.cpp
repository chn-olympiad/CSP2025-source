#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,x;
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
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int a=(i+n-1)/n;
			cout<<a<<' ';
			if(a%2==1){
				cout<<i-(a-1)*m;
			}
			else{
				cout<<a*m-i+1;
			}
			return 0;
		}
	}
	return 0;
}
