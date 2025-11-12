#include<bits/stdc++.h>
using namespace std;
string a;
int t[66];
int top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if('0'<=a[i]&&a[i]<='9'){
			top=a[i]-48;
			t[top]++;
		}
	} 
	for(int i=9;i>=0;i--){
		if(t[i]){
			while(t[i]--){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 