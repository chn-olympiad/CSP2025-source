#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned long long;
using namespace std;
const int N=5e5+10;
/*
zhangchenge
*/
int n,k,ar[N],cnt,tp;
void solve(){
	cin>>n>>k;
	f(i,1,n){
		cin>>ar[i];
		if(ar[i]>1)tp=1;
	}
	if(tp==0&&k<=1){
		if(k==1){
			f(i,1,n)cnt+=ar[i];
		}else{
			f(i,1,n){
				if(ar[i]==1&&ar[i+1]==1)cnt++,i++;
				else cnt+=!ar[i];
			}
		}cout<<cnt;
		return;
	}
	int h=1,t=0,sum=0;
	while(h<=n){
		while((sum<k||t-h+1==0)&&t<=n)sum^=ar[++t];
		if(sum==k&&t-h+1>0)cnt+=1,h=t+1,sum=0;
		while(sum>k){
			if(sum^ar[h]<=sum||sum^ar[t+1]>=sum||t>=n)sum^=ar[h++];
			else sum^=ar[++t];
		}
		if(sum==k&&t-h+1>0)cnt+=1,h=t+1,sum=0;
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)solve();
}
