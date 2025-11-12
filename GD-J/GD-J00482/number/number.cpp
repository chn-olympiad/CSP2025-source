#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-48;
			m++;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++) cout<<a[i];
	return 0;
}
