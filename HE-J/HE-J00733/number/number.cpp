#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int a[N];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
