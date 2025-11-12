#include<bits/stdc++.h>
using namespace std;
string a;
int s[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int b=a.size();
	for(int i=0;i<b;i++){
		if(48<=a[i]&&a[i]<=58){
			s[a[i]-48]++;
		}
	}for(int i=9;i>=0;i--){
		if(s[i]!=0){
			for(int j=0;j<s[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}	


