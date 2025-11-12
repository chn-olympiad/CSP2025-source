#include <bits/stdc++.h>
using namespace std;
long long pos=1;
int a[1000005];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.length());i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[pos]=s[i];
			pos++;
		}
	}
	sort(a+1,a+pos);
	for(int i=1;i<pos;i++){
		cout<<a[i];
	}
	return 0;
}
