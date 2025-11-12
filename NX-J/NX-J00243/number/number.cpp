#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string s;
	cin>>s;
	long long arr[s.size()+10]={0},k=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[k]=s[i]-'0';
			k++;
		}
	}
	sort(arr,arr+k);
	for(long long i=k-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}
