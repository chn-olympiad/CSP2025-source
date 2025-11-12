#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500006;
struct node{
	int s,e;
	node(){;}
	node(int _,int __){s=_;e=__;}
	bool operator <(node gg){
		return e<gg.e;
	}
}a[N];
int sum[N],n,cnt,k,ans;
int main(){
	freopen("xor1.in","r",stdin);//´óÑùÀý
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]^=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if((sum[i]^sum[j])==k){
				a[++cnt]=node(j,i);
				//cout<<j<<" "<<i<<endl;
			}
		}
		if(sum[i]==k){
			a[++cnt]=node(i,i);
		}
	}
	sort(a+1,a+cnt+1);
	int now=1;
	ans=1;
	for(int i=1;i<=n;i++){
		if(a[now].e<a[i].s){
			ans++;
			now=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

