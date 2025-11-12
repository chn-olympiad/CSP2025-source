#include<bits/stdc++.h>
using namespace std;
int a[10+5]={0};
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[int(s[i])]++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=a[i];j>=1;j--){
				cout<<i;
			}
		}
		
	}
	return 0;
}
