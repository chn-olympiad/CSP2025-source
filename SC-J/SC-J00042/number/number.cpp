#include<bits/stdc++.h>
using namespace std;
string s;
char arr[1000005];
long long k;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')arr[k++]=s[i];
	}
	sort(arr,arr+k,cmp);
	cout<<arr;
	return 0;
}