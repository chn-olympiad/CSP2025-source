#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001],b[10001],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(2*a[i]>=sum){
			n-=i;
			break;
		}
	}
	sum=0;
	int son=0;
	for(int i=1;i<=n;i++){
		b[i]+=a[i]+b[i-1];
	}
	for(int i=3;i<=n;i++){
		for(int o=0;o<i;o++){
			for(int p=0;p<i-2;p++){
				son+=a[o];
			if((b[i]-son)>(a[i]*2)){
				sum++;
			}
			son=0;
		}
	}
}
	cout<<sum;
	return 0;
}
