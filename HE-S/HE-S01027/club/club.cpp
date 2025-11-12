#include<bits/stdc++.h>
using namespace std;

const int N=2e4+9;
int a[N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	int sum=0;
	for(int k=0;k<t;k++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				sum=sum+a[i][j];
			}
		}
	}
	cout<<sum;
	return 0;
}

