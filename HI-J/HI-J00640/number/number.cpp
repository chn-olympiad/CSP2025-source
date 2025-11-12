#include<bits/stdc++.h>
using namespace std;
int a[1000099],k=0;
bool cmp(int a,int b){
	return a>b;
}
string l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}

