#include<bits/stdc++.h>
using namespace std;
string s;
int b[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    bool flag=false;
    int len=s.size();
    for(int i=0;i<len;i++){
	if(isdigit(s[i])){
	    b[s[i]-'0']++;
	    if(s[i]-'0'!=0){
		flag=true;
	    }
	}
    }
    if(flag){
	for(int i=9;i>=0;i--){
	    for(int j=1;j<=b[i];j++){
		cout<<i;
	    }
	}
    }else{
	cout<<0<<endl;
    }
    return 0;
}
