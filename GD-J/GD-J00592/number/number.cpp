#include<bits/stdc++.h>
using namespace std;
int arr[110];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(arr[i]--){
			cout<<i;
		}
	}
	return 0;
}
