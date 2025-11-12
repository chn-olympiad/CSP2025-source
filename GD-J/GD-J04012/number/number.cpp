#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt,arr[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[++cnt]=s[i]-'0';
		}
	}
	sort(arr+1,arr+cnt+1);
	for(long long i=cnt;i>=1;i--){
		cout<<arr[i];
	}
	return 0;
} 
