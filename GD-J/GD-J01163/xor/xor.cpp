#include<bits/stdc++.h>
using namespace std;
int n,k,l,ans;
int a[500100],s[500100];
struct st{
	int x,y;
}v[500100];
inline bool cmp(st xx,st yy){
	return xx.y<yy.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=s[j]^s[i-1];
			if(sum==k){
				v[++l].x=i;
				v[l].y=j;
			}
		}
	}
	for(int i=1;i<=l;i++)if(v[i].x>v[i].y)swap(v[i].x,v[i].y);
	sort(v+1,v+l+1,cmp);
	for(int i=1;i<=l;i++){
		int p=v[i].y;
		int mun=1;
		for(int j=i+1;j<=l;j++){
			if(p<v[j].x){
				mun++;
				p=v[j].y;
			}
		}
		ans=max(ans,mun);
	}
	cout<<ans;
	return 0;
}
