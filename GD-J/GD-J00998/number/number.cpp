#include<bits/stdc++.h>
using namespace std;
string s,b;
long long n;
int arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<=(n-1);i++){
		if(s[i]>='0' && s[i]<='9'){
			 b+=s[i];
		}
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='9') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='8') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='7') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='6') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='5') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='4') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='3') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='2') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='1') cout<<b[i];
	}
	for(int i=0;i<=(n-1);i++){
		if(b[i]=='0') cout<<b[i];
	}
	return 0;
} 

