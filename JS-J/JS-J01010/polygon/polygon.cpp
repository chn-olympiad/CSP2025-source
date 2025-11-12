#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
int s[5010],slen;
int j(int len){
	long long sum=0;
	int mx=0;
	for(int i=1;i<=len;i++){
		sum+=s[i];
		mx=max(mx,s[i]);
	}
	return sum>mx*2;
}
long long f(int r,int x,int len){
	if(!x){
		return j(len);
	}
	int sum=0;
	for(int i=r+1;i<=n-x+1;i++){
		s[++slen]=a[i];
		sum+=f(i,x-1,len);
		slen--;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
		ans+=f(0,i,i);
	cout<<ans;
	return 0;
}