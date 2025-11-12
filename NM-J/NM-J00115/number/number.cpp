#include<iostream>
using namespace std;


int main(){
	freopen(number.in,r,sdtin);
	freopen(number.out,w,stdend);
	long long s;
	cin >> s;
	int n=0; 
	for(int i=0;i<=s;i++){
		if(s[i]>=1&&s[i]<=9){
			n+=s[i]; 
		}
	}
	cout >> n;
	return 0;
	
}

