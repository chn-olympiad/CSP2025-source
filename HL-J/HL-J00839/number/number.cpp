#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6+10;
char a[N];
int b=0;
long long answer;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=  0;i<s.size();i++){
		if(isdigit(s[i])){
			a[b]=(s[i]);
			b++;
		}
	}
	for(int i = 0;i<b;i++){
		if(a[i]<a[i+1]){
			int t = a[i];
			a[i]=a[i+1];
			a[i+1] =t;
		}
	}
	for(int i = 0;i<=b;i++){
		cout<<a[i];
	}
	return 0;
}