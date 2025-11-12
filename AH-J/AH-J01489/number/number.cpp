#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=s.size();
	int arr[1000100],a=0;
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9') arr[a++]=s[i]-'0';
	}
	sort(arr,arr+a);
	for(int i=a-1;i>=0;i--) cout<<arr[i];
	return 0;
}
