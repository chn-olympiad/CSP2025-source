#include <bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int c=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			c=i;
			break;
		}
	}
	int d=c/n;
	if(d%2==0){
		cout<<d+1<<' '<<c%n+1;
	}
	else{
		cout<<d+1<<' '<<n-(c%n);
	}
    return 0;
}
