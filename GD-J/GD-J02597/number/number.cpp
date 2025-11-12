#include<bits/stdc++.h>
using namespace std;
int a[600000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]>='0'&&s[i-1]<='9'){
        	cnt++;
        	a[i]=s[i-1]-'0';
		}
    }
    sort(a+1,a+n+1);
	for(int i=n;i>n-cnt;i--)
	{
		cout<<a[i];
	 }
    return 0;
}

