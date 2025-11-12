#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int b[1000005],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	if(s.size()==1){
		cout<<s[0];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i];
			b[i]=a[i]-'0';
		}
		else{
			c++;
		}
	}
	sort(b,b+s.size(),cmp);
	for(int i=0;i<s.size()-c;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
