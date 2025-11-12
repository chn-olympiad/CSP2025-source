#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
void in(ll &num){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	num=k*f;
}
void out(ll num){
	if(num<0){
		putchar('-');
		num*=-1;
	}
	if(num<10){
		putchar(num+'0');
	}else{
		out(num/10),putchar(num%10+'0');
	}
}
ll a[5][N],cnt[5],ans,n;
ll T;
ll id[5][N];
void solve(ll tmp){
	sort(id[tmp]+1,id[tmp]+cnt[tmp]+1);
	for(ll i=1;i<=cnt[tmp]-n/2;i++){
		ans-=id[tmp][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in(T);
	while(T--){
		in(n);
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(ll i=1;i<=n;i++){
			in(a[1][i]),in(a[2][i]),in(a[3][i]);
			ll ls=max(max(a[1][i],a[2][i]),a[3][i]);
			if(ls==a[1][i]){
				cnt[1]++;
				id[1][cnt[1]]=a[1][i]-max(a[2][i],a[3][i]);
			}else{
				if(ls==a[2][i]){
					cnt[2]++;
					id[2][cnt[2]]=a[2][i]-max(a[1][i],a[3][i]);
				}else{
					cnt[3]++;
					id[3][cnt[3]]=a[3][i]-max(a[2][i],a[1][i]);
				}
			}
			ans+=ls;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			out(ans);
			putchar('\n');
		}else{
			ll mx;
			for(ll i=1;i<=3;i++){
				if(cnt[i]>n/2){
					mx=i;
				}
			}
			solve(mx);
			out(ans);
			putchar('\n');
		}
	}
	return 0;
} 
