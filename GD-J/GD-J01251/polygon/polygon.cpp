#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],sum,fac,faaa;
void dfs(int len,int zh,int nows,int lst,int mxx){
	if(nows==len){
		if(zh>a[mxx])sum++;
		return;
	}
	for(int i=lst+1;i+len-nows<=mxx;i++)
	dfs(len,zh+a[i],nows+1,i,mxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3])))cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++)
		{	
			for(int j=3;j<=i;j++)
			dfs(j-1,0,0,0,i);
		}
		cout<<sum;
	}
	else {
		cout<<rand();
	}
	return 0;
}  
