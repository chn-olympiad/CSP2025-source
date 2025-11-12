#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m;
	cin>>t;
	int a[10000];
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[k];
				if(a[k]>a[k-1]){
					m=m+a[k];
				}
			}
		}
		cout<<m<<endl;
	}
    return 0;
}
