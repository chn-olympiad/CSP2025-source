#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int l,k;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	char a[l];
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[k]=s[i];
			k++;
		}
	}
	sort(a,a+k+1,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
