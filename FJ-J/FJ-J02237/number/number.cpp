#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],x,o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			x=x*10+i;
		}
	}
	printf("%d",x);
	return 0;
}
