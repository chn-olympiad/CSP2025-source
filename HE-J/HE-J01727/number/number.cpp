#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=0;
	int x=0;
	for(int i=1;i<=s.size();i++){
		cin>>s[i];
		if((int)s[i]==s[i]){
			l++;
			x++;
			a[x]=s[i];
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
}
