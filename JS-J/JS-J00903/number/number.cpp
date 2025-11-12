#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[int(s.size())+1]={};
	int a=0;
	for(int i=0;i<int(s.size());i++){
		//cout<<1;
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			arr[a]=s[i]-'0';
			//cout<<arr[a]<<endl;
			a++;
		}
	}
	sort(arr,arr+a);
	for(int i=a-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}
