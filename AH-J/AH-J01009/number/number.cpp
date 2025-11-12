#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001],sum=0,maxx=1,n,m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<=n;i++){
		if(s[i]>'0' and s[i]<'9'){
			sum++;
			a[i]=s[i]-'9';	
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxx){
			maxx=a[i];
			}
		}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
	}
