#include <bits/stdc++.h> 
using namespace std;

const int q=1e6+5;
long long number[q],k=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		long long n;
		n=s[i]-'0';
		if(n>=0&&n<=9){
			number[k]=n;
			k++;
		}
		n=0;
	}
	sort(number,number+k);
	for(int i=k-1;i>=0;i--){
		cout<<number[i];
	}
	return 0;
}