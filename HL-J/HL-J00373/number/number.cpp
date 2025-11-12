#include <bits/stdc++.h>
using namespace std;
const int K=1e6+2;
int a[K];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
		else{
			a[i]=-1;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]>=0){
			cout<<a[i];
		}
	}
	return 0;
}
