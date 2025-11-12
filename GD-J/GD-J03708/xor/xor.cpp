#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
int n,k;
int a[maxn],cnt[maxn*6],tot,last,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=(1<<21);i++)cnt[i]=-1;
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		tot^=a[i];
		if(cnt[k^tot]>=last){
			ans++;
			last=i;
		}
		cnt[tot]=i;
	}
	cout<<ans<<endl;
	return 0;
} 
