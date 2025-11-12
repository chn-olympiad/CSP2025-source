#include <bits/stdc++.h>
using namespace std;
string s,ans;
const int N=1e6+10;
int a[N],c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+l,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}