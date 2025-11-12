#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
long long a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	//int l=1,r=1;
	long long x;
	for(long long l=1;l<=n;){
		for(long long r=l;r<=n;r++){	
			if(r==l) x=a[l];
			else{
				x=x^a[r];
			}
			if(x==k){
				cnt++;
				l=r+1;
				break;
			}
			if(r==n) l++;
		}
	}
	cout<<cnt;
	return 0;
}