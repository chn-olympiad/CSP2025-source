#include<bits/stdc++.h>
using namespace std;
int f(int a,int b){
	string a1="",b1="";
	a*=2;
	b*=2;
	if(a>b){
		int x=a;
		a=b;
		b=x;
	}
	while(a/=2) a1+=char(a%2+'0');
	while(b/=2) b1+=char(b%2+'0');
	int sum=0;
	for(int i=0;i<b1.size();i++){
		if(i>=a1.size()) sum+=(b1[i]-'0')*pow(2,i);
		else
			if(a1[i]!=b1[i]) sum+=pow(2,i);
		
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,x=0;
	cin>>n>>k;
	int s[n+1];
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=f(s[i],s[i-1]);
	}
	for(int i=1;i<=n;i++){
		//cout<<s[i]<<endl;
		for(int j=x;j<=i;j++){
			if(s[i]-s[j]==k){
				cnt++;
				x=i;
			}
		}
	}
	cout<<cnt;
	return 0;
}
