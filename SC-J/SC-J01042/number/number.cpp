#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],l;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int si=s.size();
	for(int i=0;i<si;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
}