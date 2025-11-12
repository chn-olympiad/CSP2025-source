#include <bits/stdc++.h>
using namespace std;
int cmp(int y,int x){
	return y>x;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
	int len=s.size(),b=0,a[1000000];
	for(int i=0;i<len;i++){
		if(s[i]<97){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b,cmp);
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
    return 0;
}
