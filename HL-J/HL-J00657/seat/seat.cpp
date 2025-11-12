#include<bits/stdc++.h>
using namespace std;
int n,m,a[90010],f[101][101];
int k,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			b=i;
			break;
		}
	}
	int qy=b%n;
	int cs=b/n;
	if(cs%2==0){
		if(qy>0)
		cout<<cs+1<<" "<<qy;
		else
		cout<<cs<<1;
}
	else
	if(qy>0)
	cout<<cs+1<<" "<<n-qy+1;
	else{
		cout<<cs<<" "<<n;
	}
	return 0;
}

