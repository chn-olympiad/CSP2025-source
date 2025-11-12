#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,m,a[101],s,x;
signed main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n*m;i++)a[i]=rd(),s+=(a[i]>a[1]);x=s/n+1,s++;
	if(x%2)cout<<x<<' '<<s-n*x+n;
	else cout<<x<<' '<<n*x-s+1;
	return 0;
}
