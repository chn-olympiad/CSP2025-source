#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans=0,sum=0;
int myxor(int a,int b){
	int x[30]={},y[30]={},i=1,j=1,m=0,sum=0;
	while(a!=0){
		x[i]=a%2;
		a/=2;
		i++;
	}
	while(b!=0){
		y[j]=b%2;
		b/=2;
		j++;
	}
	cout<<endl;
	for(int o=1;o<=max(i,j)-1;o++){
		if(x[o]!=y[o]) x[o]=1;
		else x[o]=0;
	}
	for(int o=max(i,j)-1;o>=0;o--){
		sum+=x[o]*pow(2,m);
		m++;
	}	
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l1=1;l1<=n;l1++){
		for(int r1=l1;r1<=n;r1++){
			sum=a[l1];
			for(int s1=l1+1;s1<=r1;s1++){
					sum=myxor(sum,a[s1]);
			}
			if(sum==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}

