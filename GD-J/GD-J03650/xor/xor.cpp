#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,a[500010];
int  b[10000+10][10000+10];
int f(int cnt){
	if(cnt+1>n)return ans;
	int ma=-1;
	for(int i=cnt+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i][j]==k){
				ans++;
				ma=max(ma,f(j));
				ans--;
			}
		}
	}
	return ma;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i][i]=a[i];
		for(int j=i+1;j<=n;j++)b[i][j]=b[i][j-1]^a[j];
	}
	cout<<f(0);
	return 0;
} 
