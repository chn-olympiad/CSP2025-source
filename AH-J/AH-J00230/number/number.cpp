#include<bits/stdc++.h>
#define N 1000005
using namespace std;
string str;
int num[N],n,len,t[20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9') t[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(t[i]){
			while(t[i]){
				cout<<i;
				t[i]--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
