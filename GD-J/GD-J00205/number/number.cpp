#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int flag=1000004;
int main(){
	freopen("number.in","r",std.in);
	freopen("number.out","w",std.out);
	cin>>s;
	for(int i=0;i<=flag;i++){
		a[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0'; 
		}
		
	}
	sort(a,a+flag);
	for(int i=flag;i>=1;i--){
		if(a[i]!=-1){
			cout<<a[i];
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
