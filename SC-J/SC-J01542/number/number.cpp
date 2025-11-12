#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=20;
int arr[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			arr[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=arr[i];j++){
			cout<<i;
		}
	}
	return 0;
}