#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &x,const int &y){
		return x>y;
}
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size(),t=0;
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}

