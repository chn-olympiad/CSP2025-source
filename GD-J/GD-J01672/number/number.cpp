#include <bits/stdc++.h>
using namespace std;
long long arr[1000006];
long long p=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin >>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[p++]=s[i]-'0';
		}
	}
	sort(arr,arr+s.length(),cmp);
	for(int i=0;i<p;i++){
		cout <<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
