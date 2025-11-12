#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
string str;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;i++)if(str[i]>='0'&&str[i]<='9')arr[++n]=str[i]-'0';
	sort(arr+1,arr+1+n);
	for(int i=n;i>=1;i--)cout<<arr[i];
	return 0;
}
