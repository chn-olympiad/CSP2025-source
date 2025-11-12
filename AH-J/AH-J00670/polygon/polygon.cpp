#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx[5005]={-0x3f},cnt;
long long s[5005];
bool check(int ans,int ma){
	return ans>(ma*2);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		maxx[i]=max(maxx[i-1],a[i]);
		if(check(s[i],maxx[i])){
			cnt=(cnt+1)%998244353;
		}
	}
	if(n<=3){
		if(check(s[n],maxx[n])) cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int j=i+1;
		while(j<=n){
			s[i+j]=s[i]+s[j];
			int p=j+1;
			while(p<=n){
				s[i+j+p]=s[i]+s[j]+s[p];
				if(check(s[i+j+p],maxx[p])){
					cnt=(cnt+1)%998244353;
				}
				p++;
			}
			if(check(s[i+j],maxx[j])){
				cnt=(cnt+1)%998244353;
			}
			j++;
			
		}
	}
	cout<<cnt%998244353;
	return 0;
}
