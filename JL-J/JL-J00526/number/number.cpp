#include<bits/stdc++.h>
using namespace std;
string s;
int sum=0,num=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
		}
	}
	int a[sum]={0};
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
} 
