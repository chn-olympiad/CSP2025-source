#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
int a[N];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x,c);
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
} 
