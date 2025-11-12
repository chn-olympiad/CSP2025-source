#include<bits/stdc++.h>
using namespace std;
long long n,k,a[2000000],m,x,maxx=INT_MIN,ans,b[2000000],cnt;
void qingkong(){
	for(int i=1;i<=cnt;i++){
		a[b[i]]=0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=1;
	b[++cnt]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&m);
		x=x^m;
		a[x]++;
		b[++cnt]=x;
		if(a[x^k]!=0&&((!((x^k)==x))||(a[x^k]==2))){
			ans++;
			qingkong();
			x=0;
			a[0]=1;
			b[++cnt]=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//a[0]
