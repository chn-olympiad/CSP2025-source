#include<bits/stdc++.h>
using namespace std;
int b[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(b,0,9);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		int in=s[i]-'0';
		if(in>=0 && in<=9){
			b[in]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]>0){
			while(b[i]--){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
