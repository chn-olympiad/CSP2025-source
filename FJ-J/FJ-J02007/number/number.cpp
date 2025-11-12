#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=(s[i]-'0');
			t++;
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<t;i++){
		cout<<a[i];
	}
}
