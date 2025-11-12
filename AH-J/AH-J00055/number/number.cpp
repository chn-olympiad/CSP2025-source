#include<bits/stdc++.h>
using namespace std;
int p[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;                          
	cin>>s;
	int n=s.size();
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	if(s.size()==2){
		int a=s[0]-'0';
		int b=s[1]-'0';
		int c=a*10+b;
		a=s[0]-'0';
		b=s[1]-'0';
		int d=a+b*10;
		cout<<max(c,d);
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		p[i]=s[i]-'0';
	}
	sort(p,p+n);
	for(int i=n-1;i>=0;i--){
		ans+=p[i]*pow(10,i);
	}
	cout<<ans;
	return 0;
}
