#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)a[++l]=s[i]-'0';
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--)cout<<a[i];

}
