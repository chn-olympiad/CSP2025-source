#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
string s;
int a[N],sj=0;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(size_t i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sj++]=s[i]-'0';
		}
	}
	sort(a,a+sj,cmp);
	for(int i=0;i<sj;i++)cout<<a[i];
	return 0;
}
