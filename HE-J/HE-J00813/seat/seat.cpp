#include<bits/stdc++.h>
using namespace std;
int a[10010],b[100][100];
int main(){
	freopen("mumber.in","r",stdin);
	freopen("mumber.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int j=1;j<=n;j++){
		if(a[j]==f){
			cout<<1<<" "<<j;
		}
	}
	int s=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j+i*n]==f&&s%2==0){
				cout<<i<<" "<<j+(n-j);
			}else if(a[j+i*n]==f&&s%2==0){
				cout<<i<<" "<<j;
			}
		}
		s++;
	}
}
