#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int c=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			char x=s[i];
			x-='0';
			a[c]=x;
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i;i<c;i++){
		cout<<a[i];
	}
	return 0;
}