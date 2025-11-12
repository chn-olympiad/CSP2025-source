#include<bits/stdc++.h> 
using namespace std;
string s;
long long a[1000005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.length() == 1){
		if(s[0] >= '0' && s[0] <= '9'){
			cout<<s;
			return 0;
		}
	}
	for(int i = 0;i < s.length();i++){
		a[i] = -1;
	}
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i] - 48;
			n++;
		}
	}
	if(n == s.length()){
		cout<<s;
		return 0;
	}
	sort(a,a+s.length());
	for(int i = s.length()-1;i >= s.length()-n;i--){
		cout<<a[i];
	}
	return 0;
}
