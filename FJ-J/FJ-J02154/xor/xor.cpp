#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],n,k,sum;
bool c[500005];
int check(int a,int b){
	return (a|b)-(a&b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(c,1,sizeof(c));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=check(b[i-1],a[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=n-i;j<=n;j++){
			int si=1;
			if(check(b[j],b[j-i])==k){
				for(int p=j-1;p<=j;p++){
					if(!c[p]){
					si=0;
					break;
					}
				}
				if(si==1){
				sum++;
				for(int p=j-1;p<=j;p++){
					c[p]=0;
				}
				}
			}
		}
	}
	cout<<sum;
}
