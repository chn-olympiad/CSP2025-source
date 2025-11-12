#include<bits/stdc++.h> 
using namespace std;
string s1;
const int N=1e7+10;
bool cmp(char a,char b){
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	char a[s1.length()]={};
	for(int i=0;i<s1.length();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[i]=s1[i];
			
		}else{
			a[i]=-1;
		}
	}
	sort(a,a+s1.length()+1);
	for(int i=s1.length();i>=1;i--){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	
	return 0;
}
