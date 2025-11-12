#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
string ans; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//提取数字
	int top=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[top]=s[i]-'0';
			top++;
		}
	} 
	//从大到小排序
	for(int i=0;i<top-1;i++){
		for(int j=0;j<top-1-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	} 
	for(int i=0;i<top;i++){
		cout<<a[i];
	}
	return 0;
}

