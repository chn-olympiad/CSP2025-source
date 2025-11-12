#include <bits/stdc++.h>

using namespace std;
long long n,a[500005],pre,cnt;
long long f(long long be,long long en){
	long long ans=pre;
	for(int i=1;i<be;i++){
		ans-=a[i];
	}
	for(int i=en+1;i<=n;i++){
		ans-=a[i];
	}
	return ans;
}
bool cec(long long be,long long en,long long h){
	if(en*2<h){
		return true;
	}else{
		return false;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre+=a[i];
	}
	sort(a,a+n+1);
	for(int i=3;i<=n;i++){
		long long be=0,en=be+i;
		if(a[be+1]!=a[be]&&a[en+1]!=en){
		for(;en<=n;en++){
			be++;
			long long h=f(be,en);
			if(cec(be,en,h)){
				cnt++;
			}
		}
	}
	}
	cout<<cnt%998244353;
	return 0; 
}
