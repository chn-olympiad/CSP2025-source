#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,b,c[10];
	int a[100][100];
	cin>>t;
	for(int w=1;w<=t;w++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[b][j];
			}
		}
		c[w]=max(a[b][w],a[b][w+1]);		
		} 
	for(int i=1;i<=t;i++){
		cout<<c[i]+c[i]<<endl;
	}
	return 0;
} 
