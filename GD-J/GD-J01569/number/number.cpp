#include<bits/stdc++.h>
using namespace std;
long long a[10];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0' && str[i]<='9'){
			int num=str[i]-'0';
			a[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
