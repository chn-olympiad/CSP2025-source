#include <bits/stdc++.h>
using namespace std;
int a[1000009];
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string str;
	cin>>str;
	int n=str.size(),j=0;
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[j]=str[i]-'0';
			j++;
		}
			
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
}
