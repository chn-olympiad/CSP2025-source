#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],s[500001],ans=0,sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++){
		sum=sum xor a[i];
		if(sum==k){
			ans++;
			sum=0;
		}
	} 
	cout<<ans;
	return 0;
}
//想到正解了，来不及了，只有不到20分钟，
//希望数据水一点，T4只有40分，估分270，好像拿不了一等 
