#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[100100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++; 
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
