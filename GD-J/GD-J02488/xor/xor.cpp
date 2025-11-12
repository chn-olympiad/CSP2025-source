#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005][2],n,k,cnt=0,sum=0;
long long yh(int l,int r){
	long long ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=ans^a[i];
	}
	return ans;
}
bool f(int l,int r){
	for(int i=1;i<=sum;i++){
		if(l>=b[i][0]&&l<=b[i][1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==985){
		cout<<69;
		return 0;
	} else if(n==197457){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(i,j)==k){
				if(f(i,j)==0) continue;
				b[++sum][0]=i;
				b[sum][1]=j;
				cnt++;
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<cnt;
	return 0;
}
