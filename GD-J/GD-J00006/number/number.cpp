#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int b[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0')b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)if(b[i])for(int j=1;j<=b[i];j++)cout<<i;
	return 0;
}
