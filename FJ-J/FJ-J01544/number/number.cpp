#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],l;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main (){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++)cout<<a[i];
	return 0;
}

