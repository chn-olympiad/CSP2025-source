#include<bits/stdc++.h>
using namespace std;
long long n;
int a[100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		for(int j=0;j<=10;j++){
			if(s[i]-'0'==j){
				a[j]++;
			}	
		}
	}
	for(int i=10;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
