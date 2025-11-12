#include<bits/stdc++.h>
using namespace std;
string s;
long long n,arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[n]=s[i]-'0';
			n++;
		}
	}
	sort(arr,arr+n);
	if(arr[0]){
		for(int i=n-1;i>=0;i--){
			cout<<arr[i];
		}
	}
	else cout<<0;
		return 0;
}
