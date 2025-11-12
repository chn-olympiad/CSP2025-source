#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005],c[5005];
void f(int step){
	if(step==n+1){
		int cnt=0,bg=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				cnt+=a[i];
				bg=max(bg,a[i]);
				cnt1++;
			}
		}
		if(bg*2<cnt&&cnt1>2)ans++;
		return;
	}
	c[step]=1;
	f(step+1);
	c[step]=0;
	f(step+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f(1);
	cout<<ans;
	return 0;
}
