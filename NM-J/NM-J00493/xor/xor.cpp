#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500010;
ll a[N],k,n,c[N],b[N][25];
ll huo(ll left,ll right){
	ll num=0,j;
	for(int i=21;i>=1;i--){
		if(b[right][i]>0){
			j=i;
			break;
		}
	}
	for(int i=1;i<=j;i++){
		if(b[right][i]-b[left][i]>0)num|=(1<<(i-1));
	}
	return num;
}
bool check(ll x){
	ll num1,num2,num3,cnt=0,op;
	for(ll l=1,r=1;r<=n;r++){
		num1=huo(l-1,r)&k;//区间或值
		if(num1==k){
			while(l<=r){
				num2=c[r]^c[l-1];
				if(num2==k){
					l=r+1;
					cnt++;
					break;
				}
				l++;
				num1=huo(l-1,r)&k;//区间或值
				if(num1!=k)break;
			}	
		}
	}
	return cnt>=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)c[i]=c[i-1]^a[i];
	for(ll i=1;i<=n;i++){
		ll x=a[i];
		ll j;
		for(j=1;j<=21;j++)b[i][j]=b[i-1][j];
		j=21;
		while(x){
			if(x%2)b[i][21-j+1]++;
			x>>=1;
			j--;
		}
	}
	ll left=0,right=N,ans;
	while(left<=right){
		ll mid=left+right>>1;
		if(check(mid)){
			ans=mid;
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
//考虑前缀异或和+贪心+双指针check+二分 
//101-->111
/*
4 0
2 1 0 3

*/

