#include<bits/stdc++.h>
using namespace std;
//记得把代码保存到D！！！ 
string s_molin;
int a[1000009];
int n; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	
	cin>>s_molin;
	for(int i=0;i<s_molin.size();i++){
		if(s_molin[i]>='0'&&s_molin[i]<='9'){
			a[++n]=s_molin[i]-'0';
			
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
