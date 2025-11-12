#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int num=s.length();
//	int num=0;
//	for(int i=0; i<s.length(); i++){
//		if((s[i]<='9') && (s[i]>='0')){
//			for(int k=0; k<)
//			num++;
//		}
//	}
	int n=num-1;
	while(n){
		for(int i=0; i<num; i++){
			if(s[i]<s[i+1]){
				int t=s[i];
				s[i]=s[i+1];
				s[i+1]=t;
			}
		}	
		n-=1;
	}
	for(int i=0; i<num; i++)
		cout << s[i];
	return 0;
}
