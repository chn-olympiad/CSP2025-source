#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],n,k,pre[N],cnt,x=1,ac;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int l=x;l<=i;l++){
			ac=pre[i]^pre[l-1];
			if(ac==k){
				cnt++,x=i+1,l=i+1;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}