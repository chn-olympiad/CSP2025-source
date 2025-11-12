#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],f[501];
long long p=998244353,sum=0;
string ss;
void baoli(int x,int s,int mm){
	if (x==n+1&&mm>=m){
		sum=(sum+1)%p;
		return;
	}
	//cout<<x<<s<<mm<<" ";
	for (int i=1;i<=n;i++){
		if (f[i]==1) continue;
		f[i]=1;
		if (s<a[i]) baoli(x+1,(ss[x-1]=='0'?s+1:s),(ss[x-1]=='1'?mm+1:mm));
		else baoli(x+1,s+1,mm);
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for (int i=1;i<=n;i++) cin>>a[i];
	baoli(1,0,0);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	//O(n!); n<=11.38 QAQ
	//max 8pts QAQ
	//n=12 neds 4s QAQ
	//AQQAQAQQAQAQQQQAQQAQAAQ
	return 0;
} 
/*
many tests not clean
parent cry two cry eyewater(
ten years OI one chang empty
dont use long long meet grandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandgrandparents
*/
//press to type some text
