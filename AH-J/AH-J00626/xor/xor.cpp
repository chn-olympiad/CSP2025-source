#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
int yh(int x,int y){
	int x1[25]={0},y1[25]={0};
	int i=1;
	while(x!=0){
		x1[i]=x%2;
		x/=2;
		i++;
	}                                                                                                                             
	int j=1;
	while(y!=0){
		y1[j]=y%2;
		y/=2;
		j++;
	}
	int sum=0;
	for(int i=1,j=1;i<=21;i++,j*=2){
		sum+=((x1[i]+y1[i])%2)*j;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=0;
	for(int i=1;i<=n;i++){
		now=yh(now,a[i]);
		if(now==k){
			sum++;
			now=0;
		}
	}
	cout<<sum;
	return 0;
}
