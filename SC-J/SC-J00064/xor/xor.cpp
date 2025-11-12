#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long b[500001];
int a1[500001];
int b1[500001];
int Xor(int a,int b){
	string s1="",s2="",s3="";
	int num=0;
	int i=0,j=0;
	while(a!=0 && b!=0){
		a1[i]=a%2;
		a/=2;
		i+=1;
		b1[i]=b%2;
		b/=2;
		j+=1;
	}
	for(int s=0;s<=i;s++){
		if(a1[s]==1)s1[s]='1';
		else s1[s]='0';
	}
	for(int m=0;m<=j;m++){
		if(b1[m]==1)s2[m]='1';
		else s2[m]='0';
	}
	for(int l=0;l<max(s1.size(),s2.size());l++){
		if(s1[l]!=s2[l]){
			s3[l]='1';
		}
		else s3[l]='0';
	}
	int f=0;
	for(int p=s3.size()-1;p>=0;p--){
		if(s3[p]=='1'){
			num=num+pow(2,f);
			f+=1;
		}
		else f+=1;
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,x=0,l=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0){
		if(a[1]==0)cout<<1;
		if(a[1]!=0)cout<<0;
		return 0;
	}
	if(n==2&&k==0){
		if(a[1]==0&&a[2]==0)cout<<2;
		if(a[1]==0&&a[2]!=0)cout<<1;
		if(a[1]!=0&&a[2]==0)cout<<1;
		if(a[1]!=0&&a[2]!=0)cout<<0;
		return 0;
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=a[j];
		ans=0;
		for(int j=l;j<=n;j++){
			ans=ans+Xor(b[j],b[j-1]);
			cout<<Xor(b[j],b[j-1])<<" ";
			b[j]=Xor(b[j],b[j-1]);
			if(ans==k){
				l=j;
				x+=1;
				break;
			}
		}
	}
	cout<<endl<<x;
	return 0;
}