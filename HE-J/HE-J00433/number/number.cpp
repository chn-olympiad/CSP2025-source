#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000010],n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		cout<<a[n-i];
	}
	return 0;
}
