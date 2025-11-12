#include<bits/stdc++.h>
using namespace std;
int s[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
		    s[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
			while(s[i]!=0){
				cout<<i;
				s[i]--;
			}
	}
	return 0;
}

