#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	ifstream in("number.in");
	ofstream out("number.out");
	string s;
	in>>s;
	
	int n=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=(int)s[i]-48;
			n++;	
		}
	}
	n=n-1;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		out<<a[i];
	} 
	in.close();
	out.close();
}
