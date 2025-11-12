#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	int k=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==x)break;
		else k++;
	}
	int y=k%n;
	if(y==0){
		cout<<k/n<<" ";
		if((k/n)%2==1)cout<<n;
		else cout<<1;
	}
	else{
		cout<<k/n+1<<" ";
		if((k/n)%2==1)cout<<n+1-y;
		else cout<<y;
	}
	return 0;
} 
