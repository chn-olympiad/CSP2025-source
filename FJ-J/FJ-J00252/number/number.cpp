#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],m;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++m]=s[i]-'0';
		}
	}sort(a+1,a+m+1);//找出数字并排序 
	for(int i=m;i>=1;i--){
		cout<<a[i]; //输出 
	} 
	return 0;
}
