#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000005],len1;
bool my(int e,int r){
	return r<e;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			a[++len1]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len1,my);
	for(int i=1;i<=len1;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}