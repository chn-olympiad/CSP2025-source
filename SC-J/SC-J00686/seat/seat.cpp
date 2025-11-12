#include<bits/stdc++.h>
using namespace std;
long long n,m,l,c,b[400];
long long a[20][20];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(i==1&&j==1){
				l=a[i][j];
			}
			c++;
			b[c]=a[i][j];
		}
	}
	sort(b+1,b+1+c,cmp);

	for(int i=1;i<=c;i++){
		if(b[i]==l){
			cout<<ceil(i*1.0/n)<<' ';
			int q=ceil(i*1.0/n);
			if(q%2==0){
				cout<<n-i%n+1;
			}else{
				cout<<i%n;
			}
			break;
		}
	}
	
	
	return 0;
}
