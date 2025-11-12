#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+l,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
