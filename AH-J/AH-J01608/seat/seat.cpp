#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[105];;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tar = a[1],res;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tar){
			res = i;
			break;
		}
	}
	if(res%n!=0) x=int(res/n)+1;
	else x=res/n;
	if(res%n==0&&x%2==0) y=1;
	else if(res%n==0&&x%2!=0) y=n;
	else if(x%2==0) y=n-res%n+1;
	else y=res%n;
	cout<<x<<" "<<y;
	return 0;
}
