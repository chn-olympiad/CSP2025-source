#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
bool cmp(const int&x,const int&y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int tmp=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++tmp]=s[i]-'0';
		}
	}
	sort(a+1,a+tmp+1,cmp);
	for(int i=1;i<=tmp;i++) cout<<a[i];
	return 0;
}