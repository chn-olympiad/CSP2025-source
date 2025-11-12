#include <bits/stdc++.h>
using namespace std;

string s,a1;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
    for(int i=0;i<=s.size();i++){
	    if(s[i]>'9'){
			a1=s.substr(0,i);
			break;
	    }
    }
	for(int j=a1.size();j>=0;j--){
		cout<<a1[j-1];
	}
	//1
	return 0;
}
