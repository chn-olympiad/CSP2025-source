#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;

string s;
int a[N],p;

bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p,cmp);
	for(int i=0;i<p;i++)cout<<a[i];
	return 0;
}
