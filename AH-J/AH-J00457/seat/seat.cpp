#include"bits/stdc++.h"
using namespace std;
int a[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[++p];
	}
	int g=a[1];
	sort(a+1,a+1+p);
	int yu;
	for(int i=1;i<=p;i++){
		if(a[i]==g){
			yu=p-i+1;
			break;
		}
	}
	if(yu%n==0){
		cout<<yu/n<<" ";
		if(yu/n%2==1){
			cout<<n-yu%n;
		}else{
			cout<<yu%n+1;
		}
	}else{
		cout<<yu/n+1<<" ";
		if(yu/n%2==1){
			cout<<n-yu%n+1;
		}else{
			cout<<yu%n;
		}
	}
	return 0;
}
