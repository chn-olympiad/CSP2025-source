#include<bits/stdc++.h>
using namespace std;
string s;
char a[10000001];
int ans;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++ans]=s[i];
	}
	sort(a+1,a+1+ans,cmp);
	for(int i=1;i<=ans;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
