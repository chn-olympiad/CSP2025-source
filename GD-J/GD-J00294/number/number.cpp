#include<bits/stdc++.h>
using namespace std;
int n,a[15];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			//from 0~9
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>=1;j--){
			printf("%d",i); 
		}
	}
	return 0;
}
