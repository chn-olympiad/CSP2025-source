#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')sum++,a[sum]=int(s[i]-'0');
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)cout<<a[i];
	return 0;
}
