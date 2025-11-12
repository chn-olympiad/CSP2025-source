#include<bits/stdc++.h>
using namespace std;
/*
string fb(int a){
	int t=a;
	string s="",s2;
	while(t){
		s2=float(t%2+48);
		s=s2+s;
		t/=2;
	}
	return s;
}

int fx(string s1,string s2){
	int n=max(s1.size(),s2.size());
	int z1=s1.size(),z2=s2.size();
	if(z1>z2){
		for(int i=1;i<=n-z2;i++){
			s2="0"+s2;
		}
	}
	else{
		for(int i=1;i<=n-z1;i++){
			s1="0"+s1;
		}
	}
	string s3="";
	int cnt=1,ans=0;
	for(int i=0;i<n;i++){
		if(s1[i]!=s2[i]){
			ans+=cnt;
			cnt*=2;
		}
	}
	return ans;
}
//cout<<fx(fb(3),fb(2));
*/
int a[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=1,c1=0,c2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)c1+=1;
		if(a[i]==0)c2+=1;
		if(a[i]!=1){
			t=2;
		}
	}
	if(t==1){
		cout<<n/2;
		return 0;
	}
	else if(t==2){
		if(k==0){
			cout<<c1/2;
			return 0;
		}
		else if(k==1){
			cout<<c1;
			return 0;
		}
	}
	return 0;
} 
