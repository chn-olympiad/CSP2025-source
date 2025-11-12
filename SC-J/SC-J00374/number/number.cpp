#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool add(char a,char b){
	return a>b;
}

int main(){
	cin>>s;
	int m=0,l=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			
		}else{
			a[l]=s[i]-'0';
			l++;
		}
		m++;
	}
	sort(a+0,a+m-1,add);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
}