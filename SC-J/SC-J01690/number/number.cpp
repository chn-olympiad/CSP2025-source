#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int temp=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			temp++;
			a[temp]=s[i]-'0';
		}
	}
	sort(a+1,a+1+temp,cmp);
	for(int i=1;i<=temp;i++){
		cout<<a[i];
	}
	return 0;
}