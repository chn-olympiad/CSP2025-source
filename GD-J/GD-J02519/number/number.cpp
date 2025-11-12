#include<bits/stdc++.h>
using namespace std;
#define N 1000006
int x[N];
int n,m,j,k,l;
string s; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			x[++k]=s[i]-'0';
		}
	}
	sort(x+1,x+1+k);
	for(int i=k;i>=1;i--)cout<<x[i];
	return 0;
} 
