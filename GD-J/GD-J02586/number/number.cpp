#include<bits/stdc++.h>
using namespace std;
int m,n,i,j=0;
int a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}	
	}
	n=10;
	while(n--){
		for(i=1;i<=a[n];i++){
			cout<<n;
		}
	}
} 
