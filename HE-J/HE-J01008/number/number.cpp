#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e6+10;
string s;
int a[N];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[j]=(int)s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	if(a[j-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
