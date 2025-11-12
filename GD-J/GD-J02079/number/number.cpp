#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
char a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	int n=s.length(),x=0;
	
	for(int i=0;i<n;i++){
		if('0'<=s[i] && s[i]<='9'){
			x++;
			a[x]=s[i];
		} 
	} 
	sort(a+1,a+n+1);
	for(int i=n;i>=x-1;i--){
		cout<<a[i]; 
	} 
	
	 
	
	
	return 0;
}
