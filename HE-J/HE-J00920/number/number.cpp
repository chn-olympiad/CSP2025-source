#include<bits/stdc++.h>
using namespace std ;
int main(){
//freopen("nember.in","r",stdin);
//freopen("nember.out","w",stdout);
string s;
cin>>s;
char a[s.size()];
long long i,w=0,j;
for(int i=0;i<s.size();i++){
	a[i]=-1;
}
for(int j=0;j<s.size();j++){
	char max='-1';
	int wei ='0';
	for(int i=0;i<s.size();i++){
		if(s[i]>max&&s[i]>='0'&&s[i<='9']){
			max=s[j];
			wei=j;
		}
	}
	if(max!=-1){
		cout<<a[j];
		
	}
}
 return 0;
} 
