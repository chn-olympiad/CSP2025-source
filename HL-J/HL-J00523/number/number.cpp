#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a,a+j+1,cmp);
	for(int i=0;i<=j;i++){
		cout<<a[i];
	}
	return 0;
}
