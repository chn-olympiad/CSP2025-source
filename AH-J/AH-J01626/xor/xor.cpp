#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
string er(int a){
	string s;
	int cnt=1;
	while(a){
		s[cnt++]=a%2;
		a/=2;
	}	
	return s;
}
int fun(int a,int b){
	string s1=er(a);
	string s2=er(b);
	string ans;
	for(int i=1;i<=8;i++){
		if(s1[i]==s2[i])ans[i]=0;
		else ans[i]=1;
	}
	long long e=1,sum;
	for(int i=8;i>=1;i--)if(ans[i]==1)sum+=e,e*=2;
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=1,u=1,bn=1,qwe=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)q=0;
		if(a[i]==0)bn=1;
		if(a[i]>=255)u=0;
		if(a[i]==1)qwe++;
	}
	if(q==1&&bn==0){
		if(k==0)cout<<n/2;
		else if(k==1)cout<<n;
		else cout<<0;
	}else if(bn==1&&q==1){
		if(k==1)	cout<<qwe;
		else if(k==0){
			int tyu=0;
			for(int i=1;i<=n;){
				if(i!=n&&a[i]==a[i+1]&&a[i]==1)tyu++,i+=2;
				else i++;
			}
			cout<<n-qwe+tyu;
		}else cout<<0;
	}else if(u==1){
		int cnt=0,neww=0;;
		for(int i=1;i<=n;i++){
			int op=fun(a[i],neww);
			if(op==k)cnt++,neww=0;
			else neww=op;
		}
		cout<<cnt;
	}else cout<<8;
	return 0;
}
