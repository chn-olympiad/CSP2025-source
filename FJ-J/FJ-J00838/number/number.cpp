#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],d=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[d]=s[i]-'0';
			d++;
		}
	}
	sort(a+1,a+d,cmp);
	for(int i=1;i<d;i++){
		cout<<a[i];
	}
	
	
	return 0;
}
