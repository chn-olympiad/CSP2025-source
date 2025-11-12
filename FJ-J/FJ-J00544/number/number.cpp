#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n=1,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s.size();
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
		else continue;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++) {
		cout<<a[i];
	}
	return 0;
}
