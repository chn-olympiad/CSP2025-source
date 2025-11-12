#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int arr[N],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			arr[++sum]=s[i]-'0';
		}
	}
	sort(arr+1,arr+1+sum);
	for(int i=sum;i>=1;i--){
		cout<<arr[i];
	}
	return 0;
}