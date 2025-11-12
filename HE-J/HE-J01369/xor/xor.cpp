#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,k,a[N],pre[N],m=0,ans=0;
int main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		for(int j=i-1;j>=m;j--)
			if((pre[i]^pre[j])==k) m=i,ans++/*,cout<<j+1<<" "<<i<<endl*/;
	}
	cout<<ans;
	return 0;
}//期望得分 100,O(n)
