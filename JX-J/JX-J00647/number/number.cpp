#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],sum,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9')	a[++sum]=s[i]-'0';
	}
	sort(a+1,a+sum+1,cmp);
	cout<<sum<<'\n';
	for(int i=1;i<=sum;i++)	cout<<a[i];
	return 0;
}
