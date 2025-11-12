#include <bits/stdc++.h>
using namespace std;
int f(int n){
	if(n==1) return 1;
	else return n+f(n-1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	int a[m][3]={};
	int b[k][n+1]={};
	int t=f(n);
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<m;i++){
		if(a[i][0]>=0 && a[i][0]<=n && a[i][1]>=0 && a[i][1]<=n){
			if(t<=0){
				break;
			}
			t-=a[i][0];
			t-=a[i][1];
			sum+=a[i][2];
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
