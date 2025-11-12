#include<bits/stdc++.h>
using namespace std;
string a;
int s=1;
int b[100001];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<=n;i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			b[s]=a[i]-48;
			++s;
		}
	}
	sort(b+1,b+s+1,cmp);
	for(int i=1;i<s;i++){
		cout<<b[i];
	}
	return 0;
}
