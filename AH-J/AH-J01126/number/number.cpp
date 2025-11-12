#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}
