#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],lena;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++lena]=s[i]-'0';
		}
	}
	sort(a+1,a+lena+1,cmp);
	for(int i=1;i<=lena;i++)printf("%d",a[i]);
	return 0;
}