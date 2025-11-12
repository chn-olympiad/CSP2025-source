#include<bits/stdc++.h>
using namespace std;

string s;
int n,a[1000001];
bool comp(int a,int b){
	return a>b;
}
 
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') a[++n]=s[i]-'0';
	sort(a+1,a+n+1,comp);
	for(int i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
    return 0;
}
