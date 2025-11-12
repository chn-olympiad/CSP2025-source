#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,f;
string s;
char e[1000];
bool cmp(char x,char y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&'9'>=s[i]){
			f++;
			e[f]=s[i];
		}
	}
	sort(e+1,e+1+f,cmp);
	for(int i=1;i<=f;i++){
		cout<<e[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
