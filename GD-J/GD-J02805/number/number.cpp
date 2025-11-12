#include<bits/stdc++.h>
using namespace std;
int a[2000005],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++top]=s[i]-48;
    sort(a+1,a+1+top);
    for(int i=top;i>0;i--) cout<<a[i];
}
