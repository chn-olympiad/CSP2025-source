#include<bits/stdc++.h>
using namespace std;
int a[178],x;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}int y=a[1];
	sort(a+1,a+1+b,cmp);
	for(int i=1;i<=b;i++){
		if(a[i]==y){
			x=i;
			break;
		}
	}
	l=(x+n-1)/n;
	cout<<l<<" ";
	if(l%2==1){
		if(x%n==0) cout<<n;
		else cout<<x%n; 
	}
	else{
		if(x%n==0) cout<<1;
		else cout<<n-(x%n-1);
	}
	return 0;
} 
