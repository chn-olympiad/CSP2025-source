#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

struct node{
	int x,y;
}l[N];
int n,a[N],k,cnt,sum[N],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long p=a[i];
		for(int j=i+1;j<=n+1;j++){
			if(p==k){
				l[++cnt].x=i,l[cnt].y=j-1;
				sum[cnt]=1,ans=max(ans,1);
				for(int q=1;q<=cnt;q++){
					if(l[cnt].x>l[q].y)
						sum[cnt]=max(sum[cnt],sum[q]+1),ans=max(ans,sum[cnt]);
				}
				break;
			}
			p=p^a[j];
		}
	}
	cout<<ans;
	return 0;
}
