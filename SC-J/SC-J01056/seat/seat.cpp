#include<bits/stdc++.h>
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
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) x=i;
	}
	int s=x%n;
	if(((x-1+n)/n)%2==1)cout<<(x-1+n)/n<<" "<<(n-s+1)%n+1;
	else  cout<<(x-1+n)/n<<" "<<s;
	return 0;
} 