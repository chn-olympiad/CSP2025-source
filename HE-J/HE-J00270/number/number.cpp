#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int k; 
int num[1000001];
int o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i = 0;i<len;i++){
		if((a[i]>='0')&&(a[i]<='9')){
			num[i]=a[i]-'0';
			o++;
		}
	}
	sort(num,num+len);
	for(int i = len-1;i>=len-o;i--){
		cout<<num[i];
	}
	return 0;
} 
