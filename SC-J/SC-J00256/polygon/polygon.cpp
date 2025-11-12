#include<bits/stdc++.h>
using namespace std;
long long spuare(int n){
	long long s=1;
	for(int i=1;i<=n;i++){
		s*=2;
	}
	return s;
}
long long sum=0;
int n,l[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<spuare(n);i++){
		int i1=i,j=1,mx=0,m=0;
		while(i1){
			if((i1&1)==1){
				
				m+=l[j];
				mx=max(mx,l[j]);
			}
			j++;
			i1=i1>>1;
		}
		
		if(double(double(m)/2)>mx){ 
			sum++;
			sum%=998244353; 
		}
	}
	cout<<sum;
	return 0;
}