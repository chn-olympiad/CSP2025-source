#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool cmp(int l,int r){
	if(r-l+1==3){
		int a1=a[l],a2=a[l+1],a3=a[r];
		if(a1+a2>a3&&a1+a3>a2&&a2+a3>a1){
			return 1;
		}else{
			return 0;
		}
	}
	return 1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(cmp(i,j)){
				sum++;
				sum%=998244353;
			}
		}
	}
	cout<<sum;
    return 0;
}

