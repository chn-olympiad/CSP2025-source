#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int number[N];

string s;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int len=s.size();
	int n=0;
	for(int i=0;i<len;i++){
		char c=s[i];
		if('0'<=c && c<='9'){
			n++;
			number[n]=c-'0';
		}
	}
	sort(number+1,number+1+n);
	for(int i=n;i>=1;i--){
		cout << number[i];
	}
	
	return 0;
}
