#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
struct tmd{
      int l,r;
}mp[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x,cnt=0;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			x=a[i];
			for(int q=i+1;q<=j;q++){
			   x=x^a[q];
			}
			if(x==k){
				mp[++cnt].l=i;
				mp[cnt].r=j;
				}
			}
		}
	if(cnt==0){
		cout<<0;
		return 0;
		}
	int tmp=mp[1].r,ans=1;
	for(int i=1;i<=cnt;i++){
		if(mp[i].l>tmp){
			ans++;
			tmp=mp[i].r;	
		}
    }
	cout<<ans;
    return 0;
}
