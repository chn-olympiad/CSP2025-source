#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	int n,a[50005],num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
		for(int i=0;i<=n-k;i++){
			int sum=0,c=0,maxn=0;
			while(c<k){
				sum+=a[i+c];
				maxn=max(maxn,a[i+c]);
				c++;
			}
			if(sum>maxn*2){
				num++;
			}
		}
		num=9;
	}
	cout<<num;
	return 0;
}
