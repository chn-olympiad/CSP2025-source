#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),j=1;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)(s[i]-'0');
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
}