#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
char m[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		m[i]=char(s[i]);
	}
	int k=0;
	for(int i=0;i<=s.size();i++){
		if(m[i]>='0'&&m[i]<='9'){
			//cout<<1<<" ";
			a[k++]=m[i]-'0';
			//cout<<(int)s[i];
		}
	}
	sort(a,a+k,greater<int>());
	for(int i=0;i<k;i++)cout<<a[i];
	return 0;
}
