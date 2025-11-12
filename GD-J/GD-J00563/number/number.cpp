#include<bits/stdc++.h>
using namespace std;
int D(int a,char s){
	char str;
	str=s;
	if(str=='1' || str=='2' || str=='3' || str=='4' || str=='5' || str=='6' || str=='7' || str=='8' || str=='9' || str=='0'){
		a=int(str)-48;
	}
	return a;
}
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	getline(cin,s);
//	cout << s;
//	char str[5005]={""};

	int a[1000005]={0};
	int a_size=-1;
	
//	for(int i=0; i<s.size(); i++){
//		str[i]=s[i];
//	}
	for(int i=0; i<s.size(); i++){
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){
			a[++a_size]=D(0,s[i]);
		}
	}
//	cout <<a_size;
	sort(a,a+a_size,cmd);
	for(int i=0; i<=a_size; i++) cout << a[i];
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
