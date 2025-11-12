#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],sum;
int cmp(int l,int r){
	int num=a[l];
	for(int i=l+1;i<=r;i++){
		num=(num^a[i]);
	}
	return num;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==0&&a[i]==0){
			sum++;
		}
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(cmp(i,j)==k){
					sum++;
					i=j+1;
				}
			}
		}
	}
    cout<<sum;
    return 0;
}

