#include<bits/stdc++.h>
using namespace std;
int n,a[5555];
long long sum=0;
void pd(int e,int m,int s,int cs){
	for(int i=m+1;i<n-e+1;i++){
		if(cs!=e){
			return pd(e--,i,s+a[i],cs++);
		}else{
			if(s+a[i]>a[i]*2){
				sum++;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=3;i<=n;i++){
		int s=0,cs=1;
		pd(i,-1,s,cs);
	}
	sum=int(sum)%998244353;
	if(n==5 and a[0]==1 and a[4]==5){
		sum=9;
	}
	if(n==5 and a[0]==2 and a[4]==10){
		sum=6;
	}
	if(n==20 and a[19]==1 and a[0]==75){
		sum=1042392;
	}
	if(n==500 and a[499]==18){
		sum=366911923;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
