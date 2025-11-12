#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int a[1001] = {};
	int c=0;
	long d=0;
	long b = s.length();
	bool z=true;
	for(int i=0;i<b;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			return 0;
		}
	}
	for(int i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c] = s[i]-48;
			c++;
			z=false;	
		}
	}
	if(z){
		return 0;
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		d = d*10 + a[i];
	}
	cout<<d<<endl;
	fclose(stdin);
	fclose(stdout);
}
