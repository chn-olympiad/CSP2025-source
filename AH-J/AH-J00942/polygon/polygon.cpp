#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5010],maxn=-1,xx,cntt;
vector<LL> ans;
void df(LL cur){
	if(cur>=xx){
		LL sum=0;
		for(LL i=0;i<xx-1;i++)sum+=a[ans[i]];
		if(sum>a[ans[xx-1]]){
			cntt++;
		}
		cntt%=998244353;
		return ;
	}
	for(LL i=ans[cur-1]+1;i<=n;i++){
		ans.push_back(i);
		df(cur+1);
		ans.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxn==1){
		LL tot=2,sum=0,nn=n*(n-1);
		for(LL i=3;i<=n;i++){
			tot*=i;
			nn*=(n-i+1);
			nn%=998244353;
			tot%=998244353;
			LL ans=nn/tot;
			sum+=ans;
			sum%=998244353;
		}
		cout<<sum%998244353;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		LL summ=0;
		ans.push_back(0);
		for(LL i=3;i<=n;i++){
			xx=i;
			df(1);
		}
		for(LL i=1;i<n;i++)summ+=a[i];
		if(summ>a[n])cntt++;
		cout<<cntt%998244353;
	}
	else{
		cout<<0;
	}
	return 0;
}
