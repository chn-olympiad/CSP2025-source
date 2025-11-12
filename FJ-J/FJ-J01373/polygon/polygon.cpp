#include<bits/stdc++.h>
using namespace std;
int n,ans,m;
int a[5010];
void f(int x,int sum,int m,int cnt){
	if(sum>m*2 && cnt>=3) ans++;
	for(int i=x+1;i<=n;i++){
		f(i,sum+a[i],max(m,a[i]),++cnt);
	}return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f(0,0,0,0);
	cout<<ans;
	return 0;
} 
