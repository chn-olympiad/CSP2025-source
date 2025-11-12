#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005];
int cnt=0;
int main(){
    //freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-48;
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;
	}else{
	    for(int i=cnt;i>=1;i--){
		    cout<<a[i];
	    }
	}
	
	return 0;
}
