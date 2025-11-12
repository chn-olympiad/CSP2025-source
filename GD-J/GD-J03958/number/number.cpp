#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string s;
int num[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-48>=0&&s[i]-48<=9){
			num[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i]>0){
			while(num[i]>0){
				cout<<i;
				num[i]--;
			}
		}
	}	
	
	return 0;
}

 
