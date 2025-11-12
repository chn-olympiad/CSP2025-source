#include<bits/stdc++.h>
const int N=5e5+7;
using namespace std;
int n,k,ans=0,mx=0;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int f=0,p=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mx) mx=a[i];
		if(a[i]==1) p++;
		if(a[i]>1){
			f=1;
			break;
		}
	}
	if(n<=2){
		if(n==1) cout<<0;
		else cout<<1;
	}
	else if(f==0){
		if(k==1) cout<<p;
		else if(k==0) cout<<p/2;
		else cout<<0;
	}
	else{ 
		if(k>mx){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			int q=i-1,cnt=0,sum;
			while(q<n){
				q++,sum=a[q];
				while(sum!=k&&q<n){
					q++;
					sum^=a[q];
				}
				if(sum==k) cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
