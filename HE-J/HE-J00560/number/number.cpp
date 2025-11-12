#include<bits/stdc++.h>
using namespace std;
string s;
long long n[10000005],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]-'0'<=9){
			n[cnt]=s[i]-48;
			cnt++;
		}
	}
	sort(n,n+cnt,greater<int>());
	for(int i=0;i<=cnt-1;i++){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
