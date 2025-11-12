#include<bits/stdc++.h>
using namespace std;
long long n,ac[500005],k,a[500005][500005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",ac[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[i][j]=(a[i][j-1]xor ac[j]);
			if(i==j)a[i][j]=ac[i];
		}
	}
	int sum=0,b=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i][j]==k && i!=b){
				sum+=1;
				b=j;
			}
		}
	}
	cout<<sum;
	return 0;
}
