#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++cnt]=a[i]-'0';
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<b[i];
	return 0;
}