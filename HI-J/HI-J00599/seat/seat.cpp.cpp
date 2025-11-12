#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int w=a[1];
	int q;
	int nm=n*m;
	sort(a+1,a+nm+1);
	for(int i=nm;i>=1;i--){
		if(w==a[i]){
			q=i;
			break;
		}
	}
	q=nm-q+1;
	
	int c=q%n;
	int r;
	if(q%n==0){
	 c=n;
	 r=c/n;
}
   else r=q/n+1;
if(r%2==0) c=n-c+1;
	 cout<<r<<' '<<c;
	return 0;
} 
