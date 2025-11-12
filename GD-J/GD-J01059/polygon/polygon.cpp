#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned long long;
using namespace std;
const ll N=5e3+10;
const ll M=998244353;
/*
zhangchenge
*/
ll n,cnt,j[N];
ll ar[N],sum[N],h,fg,t,tp;
void solve(){
	j[0]=1;
	cin>>n;
	f(i,1,n){
		cin>>ar[i],sum[i]=sum[i-1]+ar[i];
		if(ar[i]!=1)tp=1;
	}
	if(n==3){
		int a=ar[1],b=ar[2],c=ar[3];
		if(max(a,max(b,c))*2<a+b+c)cout<<1;
		else cout<<0;
		return;
	}else if(tp==0){
		cout<<(n-1)*(n-2)%M;
		return ;
	}
	f(i,1,n)j[i]=j[i-1]*2%M;
	sort(ar+1,ar+n+1);
	f(i,3,n){
//		h=i-2,t=i-1;
//		while(h>0&&t>0){
//			while(sum[t]-sum[h-1]>=ar[i]&&t-h+1>=2){
//				cnt=(cnt+j[i-1-(t-h+1)])%M;
//				cout<<h<<" "<<t<<" "<<i<<endl;
//				t--;
//			}
//			while(sum[t]-sum[h-1]<ar[i]||t-h+1<2){
//				//cout<<h<<" "<<t;
//				cnt=(cnt+check(t+1,i-1,))
//				if(h==0)break;
//				h--;
//			}
//		}
		h=1,t=2,fg=1;
		while(h<i&&t<i){
			while(sum[t]-sum[h-1]>ar[i]&&t-h+1>=2){
				if(fg==0)cnt=(cnt+j[(h-2>=0?h-2:0)]+j[(i-t-2>=0?i-t-2:0)]+(j[(h-2>=0?h-2:0)]-1)*(j[(i-t-2>=0?i-t-2:0)]-1)-1)%M,cout<<h<<" "<<t<<" "<<i<<" "<<j[(h-2>=0?h-2:0)]+j[(i-t-2>=0?i-t-2:0)]+(j[(h-2>=0?h-2:0)]-1)*(j[(i-t-2>=0?i-t-2:0)]-1)-1<<endl;
				else fg=0,cnt=(cnt+j[(h-1>=0?h-1:0)]+j[(i-t-2>=0?i-t-2:0)]+(j[(h-1>=0?h-1:0)]-1)*(j[(i-t-2>=0?i-t-2:0)]-1)-1)%M,cout<<h<<" "<<t<<" "<<i<<" "<<j[(h-1>=0?h-1:0)]+j[(i-t-2>=0?i-t-2:0)]+(j[(h-1>=0?h-1:0)]-1)*(j[(i-t-2>=0?i-t-2:0)]-1)-1<<endl;
				h++;
			}
			while(sum[t]-sum[h-1]<=ar[i]||t-h+1<2){
				//cout<<h<<" "<<t;
				int l=t+2,r=i-1,mid;
//				while(l<=r){
//					ar[]
//				}
				if(t==i)break;
				t++,fg=1;
			}
		}
	}cout<<cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)solve();
}
