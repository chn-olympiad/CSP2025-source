#include<bits/stdc++.h>
using namespace std;
string s;
long long arr[1000099],j=1,i=0,k=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if((48<=int(s[i]))&&(int(s[i])<=57)){
			arr[j]=int(s[i])-48;
			j++;
		}
	}
	sort(arr+1,arr+j);
	for(int i=j-1;i>0;i--)
			cout<<arr[i];
	return 0;		
}
