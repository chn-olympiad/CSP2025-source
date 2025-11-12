#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
    	if(s[i]-'0'<45){
    	
    			a[p++]=s[i]-'0';
		}
    
	}
	
	sort(a+0,a+p);
	
	for(int i=p-1;i>=0;i--){
		cout<<a[i];
	
	}
	
	return 0;
} 
