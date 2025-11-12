#include<bits/stdc++.h>
using namespace std;
string a;
int b[10000],k=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++)
		if(a[i]>='0'&&a[i]<='9'){k++;b[k]=a[i];b[k]-=48;}
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=k;i++)cout<<b[i];
	return 0;
}
