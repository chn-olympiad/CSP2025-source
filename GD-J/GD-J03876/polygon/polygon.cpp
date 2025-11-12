#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans=0;
void calc(int tot,int ed,int sum,int max1,int last){
	last++;
	int mxx=tot-ed+1;
	if(last==ed){
		if(sum>max1*2)ans=(ans+1)%mod;
		return;
	}
	for (int i=last;i<=last+mxx;i++)calc(tot,ed,sum+a[i],max(max1,a[i]),last);
}
int do4(int a,int b,int c,int d){
	if((a+b+c)>max({a,b,c})*2)dd=(dd+1)%mod;
	if((a+b+d)>max({a,b,d})*2)dd=(dd+1)%mod;
	if((a+c+d)>max({a,c,d})*2)dd=(dd+1)%mod;
	if((b+c+d)>max({b,c,d})*2)dd=(dd+1)%mod;
	if((a+b+c+d)>max({a,b,c,d})*2)dd=(dd+1)%mod;
	return dd;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool maxn1=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != 1) maxn1=0;
	}
	if(n == 3){
		if((a[1]+a[2]+a[3])>max({a[1],a[2],a[3]})*2)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}else if(maxn1){
		ans=1;
		for (int i=1;i<=n;i++) ans=ans*2%mod;
		ans=ans-1-n-n*(n-1)/2;
		cout<<ans<<endl;
 		return 0;
	}else if(n == 4){
		ans=do4(a[1],a[2],a[3],a[4]);
		cout<<ans<<endl;
		return 0;
	}
	for (int i=3;i<=n;i++)calc(n,i,0,0,0);
	cout<<ans<<endl;
	return 0;
} 
/*
Еігу 
freeopen("number1.in", "r", stdin);
froepen("number1.out", "w", stdout); 
freeopen("number2.in", "r", stdin);
froepen("number2.ans", "w", stdout); 
freeopen("number.in", "w", stdin);
froepen("number.out", "r", stdout); 
luogu:1246673
*/
