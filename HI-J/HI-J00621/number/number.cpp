#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a+0,a+s.size()+1,cmp);
	for(int i=0;i<sum;i++){
		printf("%d",a[i]);
		if(i==0&&a[i]==0){
			return 0;
		}
	}
	return 0;
}
