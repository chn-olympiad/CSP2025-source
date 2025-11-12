#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000005]={-1};
bool flag[2]={0};
int z=0;
int main(){

freopen("number.in",'r',stdin);
freopen("number.out",'w',stdout);
string s;
cin>>s;


if(s.size()<=1){
	cout<<s;return 0;
}
if(s.size()<=2){
		
		
		if((s[0]-'0')*10+(s[1]-'0')>=(s[1]-'0')*10+(s[0]-'0')){
				cout<<(s[0]-'0')*10+(s[1]-'0');
				return 0;
					}
					else{
				cout<<(s[1]-'0')*10+(s[0]-'0');
				return 0;
			}
		}
	
		
for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}else{
			a[i]=-1;
		}
}
sort(a,a+s.size(),cmp);
for(int i=0;i<s.size();i++){
	if(a[i]==-1){
		z++;
	}
}
for(int i=0;i<s.size()-z;i++){
	cout<<a[i];
	}
return 0;
} 
