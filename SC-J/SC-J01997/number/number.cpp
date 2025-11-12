#include<iostream>
#include<cstdio>
#include<string> 
using namespace std;
string s;
int z[1000001];
int a=0;
int b,c;	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			a++;
			z[a]=s[i]-48;
		}
	}
	for(int i=0;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(z[i]>z[j]){
				b=z[i],c=z[j];
				z[i]=c,z[j]=b;
			}
		}
	}
	for(int i=a;i>=1;i--){
		cout<<z[i];
	}
	return 0;
} 
//输入后，找出所有的数字，接着从小到大进行排列。
//最后倒序输出 