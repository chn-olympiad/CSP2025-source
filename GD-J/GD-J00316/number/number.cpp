#include<bits/stdc++.h>
using namespace std;
long long p,n,m,j,i,k,l,b[1000000],z,t,r,y,a[1000000],v[1000000];
string s;
bool pp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1,pp);
	for (i=1;i<=t;i++){
		if(a[i]=='0'&&p==0);
		else if(a[i]!=0){
			p=1;
			cout<<a[i];
		}
		else if(a[i]==0&&p==1){
			cout<<0;
		}
	}
	if(p==0)cout<<0;
} 
