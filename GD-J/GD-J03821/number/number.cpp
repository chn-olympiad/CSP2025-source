#include<bits/stdc++.h>
using namespace std;
int a[100000000],j,max=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	for(int i = 0;i<s1.length();i++){
		if(s1[i]-'0'>=0&&s1[i]-'0'<=9){
			a[j++]=s1[i]-'0';
		}
	}
	sort(a,a+j,cmp);
	for(int i = 0;i<j;i++){
		cout<<a[i];
	}
	return 0;

	
} 
