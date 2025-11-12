#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005]={},f=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
	if(s[i]<='9'&&s[i]>='0'){
		a[f]=int(s[i])-48;
		f++;
		}	
	}
	f-=1;
	sort(a+1,a+f+1);
	if(a[f]==0){
		cout<<0;
		return 0;
	}
	for(int i=f;i>=1;i--){
		cout<<a[i];
	}
    return 0;
} 
