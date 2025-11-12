#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat","w",stdin);
	//freopen("seat","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[(n+1)*(m+1)],t=0,y=0;
	for(int i=1;i<=n*m;i++){
		
			cin>>a[i];
		
	}
	t=a[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
						y=a[i];
						a[i]=a[j];
						a[j]=y;
			}
		}
	}
	for(int i=1;i<=n*m;i++){//cout<<a[i];
		if(a[i]==t){
			
			cout<<(i-1)/m+1<<" ";
			if(((i-1)/m+1)%2==0){
				cout<<m-i%m+1;
				break;
			}
			cout<<i%m+1;
			break;
		}
	}
	return 0;
}
