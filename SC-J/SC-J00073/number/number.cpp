#include<bits/stdc++.h>
using namespace std;
char a[1000005];
bool my_cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			p++;
			a[p]=s[i];
		}
	}
	sort(a+1,a+p+1,my_cmp);
	for(int i=1;i<=p;i++)cout<<a[i];
	return 0;
}
//I love CCF very much