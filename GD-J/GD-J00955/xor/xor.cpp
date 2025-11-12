#include<bits/stdc++.h>
using namespace std;
int n,k,l=1,r=1,ans,cnt;
long long a[500010],pre[500010];
bool isA=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			isA=false;
		}
		pre[i]=pre[i-1] xor a[i];
	}
	if(k==0&&isA){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		l=i;
		r=l+1;
		cnt=0;
		for(;l<=n,r<=n;){
			int tmp;
			if(l==1){
				tmp=pre[r];
			}else{
				tmp=pre[r] xor pre[l-1];
			}
			if(tmp==k){
				cnt++;
				l=r+1;
			}
			r++;
		}
		ans=max(ans,cnt);
	}
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}
