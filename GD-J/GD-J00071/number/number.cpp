#include<bits/stdc++.h>
using namespace std;
string a={};
int b[300]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		b[a[i]]++;
		
	}
	for(int i='9';i>='0';i--){
		for(int j=b[i];j>0;j--){
			printf("%c",i);
		}
	}
	
	return 0;
}
