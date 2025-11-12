#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],cnt=0;
int twototen(int x){
	int sum=0,po=1;
	while(x){
		sum+=(x%10)*po;
		x/=10;
		po*=2;
	}
	return sum;
}
int tentotwo(int x){
	string s="";
	while(x){
		s+='0'+x%2;
		x/=2;
	}
	int m=0;
	for(int i=s.size()-1;i>=0;i--){
		m*=10;
		m+=s[i]-'0';
	}
	return m;
}
bool xorcal(int l,int r){
	if(l==r&&a[l]==k)	return 1;
	int ans=0;
	int si,b,x,bl,si1,bl1;
	for(int i=l;i<=r;i++){
		si=0,b=ans,x=tentotwo(i),bl=x,si1=0,bl1=0;
		while(b){
			b/=10;
			si++;
		}
		while(bl){
			bl/=10;
			si1++;
		}
		for(int j=1;j<=max(si,si1);j++){
			bl1*=10;
			if((x/pow((long long)(10),max(si,si1))==0&&ans/pow((long long)(10),max(si,si1))==0)||(x/max((long long)(10),max(si,si1))==1&&ans/pow((long long)(10),max(si,si1))==1))	bl1+=0;
			else	bl1+=1;	
			x/=10;
			ans/=10;
		}
		ans=bl1;
	}
	ans=twototen(ans);
	if(ans==k)	return 1;
	return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xorcal(i,j))	cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
