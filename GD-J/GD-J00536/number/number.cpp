#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000005];
int sl;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++sl]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+sl,cmp);
	for(int i=1;i<=sl;i++) cout<<a[i];
	return 0;
} 
