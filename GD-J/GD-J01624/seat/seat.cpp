#include<bits/stdc++.h>
using namespace std;
int a[105];
int s[11][11];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int b;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			b=n*m-i+1;
		}
	}
	int x,y;
	
	cout<<y<<" "<<x;
	return 0;
}
