#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t[500005],sum,now,b;
int main(){
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a[i]=a[i]^a[i-1];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++){
			b=a[i]^a[j];
			if(b==k){
				t[i+1]=j;
				break;
			}
		}
	for(int i=1;i<=n;i++){
		if(t[i]!=0){
			if(i>now){
				sum++;
				now=t[i];
			}else{
				if(t[i]<now) now=t[i];
			}
		}
	}
	cout<<sum;
	return 0;
} 
