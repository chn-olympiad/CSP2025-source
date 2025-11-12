#include<bits/stdc++.h>
using namespace std;
string s;
int u[1000005],v,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			v++;
			u[v]=s[i]-'0';
		}
	}
	sort(u+1,u+v+1);
	for(int j=v;j>=1;j--){
		cout<<u[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
