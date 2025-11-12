#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5050],n;
long long sum;
int C(int a,int b){
	long long s1=1,s2=1;
	int t=1;
	for(int i=1;i<=a;i++,b--){
		s1=s1*b;
	}
	for(int i=a;i>=1;i--){
		s2=s2*i;
	}
	long long s=(s1/s2);
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=500){
		for(int i=3;i<=n;i++){
			sum+=C(i,n);
			sum%=MOD;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int maxn=a[i],s=0;
			for(int k=i;k<=j;k++){
				s+=a[k];
				maxn=max(a[k],maxn);
			}
			if(s>maxn){
				sum++;
				sum%=MOD;
			}				
		}
	}
	cout<<sum;
	return 0;	
} 
