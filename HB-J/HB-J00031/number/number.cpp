#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],i;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size(),n1=0;
	for(i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i+1]=a[i]-'0';
			n1++;
		}
	}
	sort(b+1,b+1+n,cmp);
	for(i=1;i<=n1;i++)cout<<b[i];
	return 0;
}
