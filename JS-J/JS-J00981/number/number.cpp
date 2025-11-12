#include<bits/stdc++.h>
using namespace std;
int n[1000005],k,m;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s.size();
	for(int i=0;i<m;i++){
		if(s[i]>='0' and s[i]<='9'){
			n[++k]=s[i]-'0';
		}
	}
	sort(n+1,n+k+1);
	for(int i=k;i>=1;i--){
		printf("%d",n[i]);
	}
	return 0;
}
