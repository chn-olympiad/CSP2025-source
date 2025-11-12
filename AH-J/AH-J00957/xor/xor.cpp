#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int num[500005];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int res=0,cnt=0;
		for(int j=i;j<=n;j++){
			res^=a[j];
			if(res==k||a[j]==k) cnt++,res=0;
		}
		if(cnt>=x) return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int t=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=k) f=0;
		else num[1]++;
	}
	if(f){
		cout<<n<<endl;
		return 0;
	}
	if(t==k) ans=1;
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(!check(mid)) r=mid-1;
		else{
			ans=mid;
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

