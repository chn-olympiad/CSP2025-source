#include<bits/stdc++.h>
using namespace std;
long long b;
int main(){
	freopen("number.in","r",in)
	freopen("number.out","w",out)
	string s;
	string n;
	cin>>s;
	for(int i = 0;i < s.size();i++){
		n[i] = '0';
	}
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n[b] = s[i];
			b++;
		}
	}
	for(int j = 0;j < s.size();j++)
		for(int i = 0;i <= j;i++){
			if(n[j] > n[i]){
				int k = n[j];
				n[j] = n[i];
				n[i] = k;
			}
		}
	for(int i = 0;i < b;i++){
		cout<<n[i];
	}
return 0;
}

