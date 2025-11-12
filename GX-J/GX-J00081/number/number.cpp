#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000001];
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	for(int j=9;j>=0;j--){
        for(int i = ans-1;i>=0;i--){
            if(a[i]==j){cout<<j;}
        }
	}
	return 0;
}

