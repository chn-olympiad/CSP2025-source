#include<bits/stdc++.h>
using namespace std;
long long n,k,a[50000],p,dp[50000][50000],mx,gg;
string s,s1,ss,ss1,g,g1;
string e(int d){
	ss="",ss1="";
	while(d){
		ss=ss+char(d%2+48);
		d=(d-(d%2))/2;
	}
	for(int i=sizeof(ss)-1;i>=0;i--)
	ss1=ss1+ss[i];
	return ss1;
}
int h(int x,int y){
	p=0;
	g="",g1="";
	s=e(x),s1=e(y);
	if(sizeof(s)>sizeof(s1)){
		for(int i=0;i<sizeof(s)-sizeof(s1);i++)
		g+='0';
		s1=g+s1;
	}
	if(sizeof(s1)>sizeof(s)){
		for(int i=0;i<sizeof(s1)-sizeof(s);i++)
		g+='0';
		s=g+s;
	}
	for(int i=0;i<sizeof(s);i++){
		if(s[i]!=s1[i])p=p+pow(2,sizeof(s)-i-1);
	}
	return p;
}
int h1(int x1,int y1){
	long long num=a[x1]; 
	for(int i=x1+1;i<=y1;i++)
	num=h(num,a[i]);
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)dp[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
			gg=h1(i,j);
			if(gg==k&&i!=j)dp[i][j]++;
//			dp[i][j]+=dp[1][i-1];
			mx=max(mx,dp[i][j]);
		}
	}
//	cout<<dp[3][3]<<" ";
	cout<<mx;
	return 0;
}
