#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int k=1;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=int('0') && int(s[i])<=int('9')) {
			a[k]=int(s[i]);
			k++;
		}
	}sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<char(a[i]);
	}
	return 0;
}
