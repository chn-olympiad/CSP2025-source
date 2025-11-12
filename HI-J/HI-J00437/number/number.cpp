#include <bits/stdc++.h>
using namespace std;
string s,q;
string a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout)
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(96<=s[i]&&s[i]<=122){
			continue;
		}
		else{
			q+=s[i];
		}
	}
	int n=q.size();
	for(int i=0;i<n;i++)
	{
		a[i]=q[i];
	}
	sort(a,a+q.size());
	for(int i=q.size();i>=0;i--)
	{
		cout<<a[i];
	}
}
