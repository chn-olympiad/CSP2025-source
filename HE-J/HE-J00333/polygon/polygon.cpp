#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353,N=5047;
int n,a[N],b[N],u=1,cnt,m;
void fun(int l,int up){
	if(up==0)return;
	else
		for(int i=l+1;i<=n;i++){
			b[u]=a[i];
			u++;
			fun(i,up-1);
		}
}
bool check(int s[],int l){
	int sum=0,ma=0;
	for(int i=1;i<=l;i++){
		sum+=s[i];
		ma=max(ma,s[i]);
	}
	if(ma*2<sum)return 1;
	else return 0;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=n-2;i>=1;i--)
		for(int j=i;j>=1;j--)m+=j;
	int b[m+10];
	for(int i=1;i<=m+10;i++)b[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>3)
		for(int i=1;i<=n-2;i++)
			for(int j=3;i<=n;i++){
				u=1;
				fun(i,j);
				if(check(b,u)==1){
					cnt++;
					cnt%=M;
				}
				for(int i=1;i<=u;i++)b[i]=0;
			}
	else if(n==3){
		int ma=0,sum=0;
		for(int i=1;i<=3;i++){
			ma=max(ma,a[i]);
			sum+=a[i];
		}
		if(sum>ma*2)cnt++;
	}
	else if(n==3)cnt=0;
	cout<<cnt;
	return 0;
}
