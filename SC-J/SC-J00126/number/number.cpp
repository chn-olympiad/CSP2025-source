#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string x;
	string pp;
	int a=0,b=1,c=0,g=0;
	cin >> s;
	for(int i = s.size();i>0;i-=1){
		for(int j = s.size();j>0;j-=1){
			if(s[a]<s[b]){
				int n=s[a];
				int m=s[b];
				s[a]=m;
				s[b]=n;
				a+=1;
				b+=1;
			}
			x = s;
			if(s[a]>=s[b]){
				a+=1;
				b+=1;
			}			
			
		}
		a=0;
		b=1;
	}
	cout << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 