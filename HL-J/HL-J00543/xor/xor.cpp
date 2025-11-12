#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long int k,y,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			y=l;
			for(int i=l+1;i<=r;i++){
				y^=a[i];
			}
			if(y==k){
				sum++;
			}
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
