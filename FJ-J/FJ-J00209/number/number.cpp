#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--) {
		if(a[i]>0){
			for(int j=0;j<a[i];j++) cout<<i;
		}
	}
    return 0;
}

