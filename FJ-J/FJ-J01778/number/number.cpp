#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char n[100005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int t = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '1') n[++t] = s[i];
		else if(s[i] == '2') n[++t] = s[i];
		else if(s[i] == '3') n[++t] = s[i];
		else if(s[i] == '4') n[++t] = s[i];
		else if(s[i] == '5') n[++t] = s[i];
		else if(s[i] == '6') n[++t] = s[i];
		else if(s[i] == '7') n[++t] = s[i];
		else if(s[i] == '8') n[++t] = s[i];
		else if(s[i] == '9') n[++t] = s[i];
		else if(s[i] == '0') n[++t] = s[i];
	}
	if(t==1){
		cout<<n[t];
	}else{
		for(int i=1; i<t; i++){
			for(int j=i; j<t; j++){
				if(n[j] < n[j+1]){
					int d = n[j];
					n[j] = n[j+1];
					n[j+1] = d;
				}
			}
			cout<<n[i];
		}
		cout<<n[t];
	}
	
	return 0;
}
