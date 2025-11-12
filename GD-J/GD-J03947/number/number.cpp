#include<bits/stdc++.h>
using namespace std;
string s;
int n,k=0,l[1000011];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if('0'<=s[i] && s[i]<='9'){
			l[++k]=int(s[i]-'0');
		}
	}
	sort(l+1,l+k+1);
	for(int i=k;i>=1;i--){
		printf("%d",l[i]);
	}
	return 0;
}
