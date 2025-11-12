#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	int a[k+1];
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+k+1,cmp);
	bool f=0;
	int t=1;
	for(int i=1;i<=m;i++){
		if(f==0){
			for(int j=1;j<=n;j++){
				if(a[t]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			}
		}
		else if(f==1){
			for(int j=n;j>=1;j--){
				if(a[t]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
				t++;
			}
		}
		f=!f;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
98 99 100 97
*/
