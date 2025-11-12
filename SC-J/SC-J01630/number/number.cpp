#include<bits/stdc++.h>
using namespace std;

int a[12]; 
string num;
 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[int(s[i]-'0')]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int i1=0;i1<a[i];i1++){
				num=num+char(i+'0');
			}
		}
	}
	cout<<num;
	return 0;
}

