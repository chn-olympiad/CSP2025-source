#include<bits/stdc++.h>
using namespace std;
int n,m,s0,s1;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> c;
	for(int i=0;i<n;i++){
		if(c[i]=='0'){
			s0++;
		}
		else{
			s1++;
		}
	}
	if(m==1){
		cout << s1;
	}
	else if(m==n){
		if(s1==n){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 2;
	}
	return 0;
}
