#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],ans=-1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int maxn=0,z=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(maxn<s[j]){
				maxn=s[j];
				z=j;
			}
		}
		maxn=0;
		a[i]=s[z];
		s[z]=0;
	}
	int l=1,r=2,sum=0;
	maxn=0;
	for(int i=1;i<=n;i++){
		l=1,r=i+1;
		while(true){
			if(r>n) break;
			for(int j=l;j<=r;j++){
				sum+=a[j];
				if(maxn<a[j]) maxn=a[j];
			}
			if(sum>maxn){
				ans++;
				l=r;
				r+=i;
				sum=0;
				maxn=0;
				cout<<l<<" "<<r<<" "<<endl;
			}
		}
		
	}
	cout<<ans%998244353;
	
	return 0;
}
