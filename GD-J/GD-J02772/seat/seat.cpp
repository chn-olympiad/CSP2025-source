#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,x=1,y=0,op;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	cout<<(k+n-1)/n<<" ";
	if((k+n-1)/n%2)cout<<k%n;
	else cout<<n+1-k%n;
	return 0;
} 
