#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
