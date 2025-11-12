#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size(),t=1;
	for(int i=0;i<len;i++){
		if(a[i]>=48&&a[i]<=57){
			b[t]=a[i]-48;
			t++;
		}
	}
	sort(b+1,b+t,cmp);
	for(int i=1;i<=t-1;i++)cout<<b[i];
	return 0;
}
