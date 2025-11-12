#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[109];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tot=n*m;
	cin>>a[0];
	int ans=a[0]; 
	for(int i=1;i<tot;i++){
		cin>>a[i];
	}
	sort(a,a+tot,cmp);
	
	int k=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}else if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[k]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
