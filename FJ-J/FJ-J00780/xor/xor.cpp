/*
by Xiao
xor(^)
按位取异或（相同为0，不同为1）
例如3^2=11(2)^10(2)=01(2)=1 
观察到5^2=7,5^7=2
5^3=6 5^6=3 
114514^10086=104500 114515^104500=10086
242930824^35034798=208421414
242930824^208421414=35034798
故猜想：若n^m=k，则n^k=m
n^0=n
即前缀异或数组是正确的
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k;
int a[N],b[N];
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	int zc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)zc++;
	}
	b[0]=0;
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	/*for(int i=0;i<=n;i++){
		cout<<b[i]<<' ';
	}*/
	if(n<=2&&k==0){
		if(n==1)cout<<zc;
		else {
			if(a[1]==a[2]&&zc==0)cout<<1;
			else cout<<zc;
		}
		return 0;
	}
	int cnt=0;
	int ans=0;
	for(int i=1,l=i;i<=n;i++){
		cnt=0;
		l=i;
		for(int r=l;r<=n;r++)
		{
			if((b[r]^b[l-1])==k) {
				cnt++;
				//cout<<(b[r]^b[l-1])<<' '<<l<<' '<<r<<endl; 
				l=r+1;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
} 
