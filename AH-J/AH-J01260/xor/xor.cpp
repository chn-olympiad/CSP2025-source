#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const L N=5*1e5+10;
int a[N],b=0,c=0,d=0;
int su(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum^=a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			b++;
		}
		else if(a[i]==0){
			c++;
		}
		else{
			d++;
		}
	}
	if(d==0){
		if(c==0){
			cout<<n;
		}
		if(c!=0){
			if(k==0){
				cout<<n;
			}
			else{
				cout<<max(b,c);
			}
		}
	}
	else{
		cout<<d;
	}
	return 0;
}
