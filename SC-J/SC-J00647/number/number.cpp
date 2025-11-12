#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+10;
string s;
long long a[N];
bool check(char a){
	int num=a-'0';
	if(num>=0&&num<=9)return 1;
	return 0;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int index=1;
	
	for(int i=0;i<s.size();i++){
		if(check(s[i])){
			a[index]=s[i]-'0';
			index++;
		}
	}
	sort(a+1,a+index,cmp);
	for(int i=1;i<index;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}