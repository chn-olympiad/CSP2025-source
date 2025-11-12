#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),w=1;
	for(int i=0;i<n;i++)
		if(s[i]>='0' && s[i]<='9'){
			a[w]=(int)(s[i]-'0');
			w++;
		}
	sort(a+1,a+w,cmp);
	for(int i=1;i<w;i++) cout<<a[i];
	return 0;
}