#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(int)s[i]-48]+=1;
		}
	}
	for(int i=0;i<10;i++){
	    while(a[9-i]!=0){
	    	cout<<9-i;
	    	a[9-i]-=1;
	    	if(a[9-i]==0) break;
		}
	}
	return 0;
}
