#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,f,ans;
int a[200001];
/*int nxor(int x,int y)
{
	if(x<y) swap(x,y);
	int m=0;
	string s1="",s2="";
	while(x){
		s1=s1+char(x%2);
		x/=2;
	}
	while(y){
		s2=s2+char(y%2);
		y/=2;
	}
	int l1=s1.size(),l2=s2.size();
	int p=l1-l2;
	for(int i=l2-1;i>=0;i--){
		if(s1[i+p]==s2[i])   s1[i+p]=0;
		else s1[i+p]=1;
	}
	for(int j=1,i=l1-1;i>=0;i++,j*=2){
		if(s1[i]=='1') m+=j;
	}
	return m;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) f=1;
	}
	if(f==0) cout<<n/2;
	else{
		if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
		}
		else{
			for(int i=1;i<=n;i++)
				if(a[i]==0 || (a[i]==1 && a[i-1]==1 && a[i-2]==0) ) ans++;
		}
		cout<<ans;
	}
	return 0;
}
