#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}for(int i=1;i<=n*m;i++){
		bool f=false;
		for(int j=2;j<=n*m;j++){
			if(a[j-1]<a[j]){
				if(j-1==b)b=j;
				else if(j==b)b=j-1;
				swap(a[j-1],a[j]);
				f=true;
			}
		}if(f==false)break;
	}
	if(b%n!=0){
		cout<<b/n+1<<' ';
		if((b/n+1)%2==0){
			cout<<m-b%n+1;
		}else {
			cout<<b%n;
		}
	}
	else {
		cout<<b/n<<' ';
		if((b/n)%2==0)cout<<'1';
		else cout<<m;
	}
	return 0;
} 