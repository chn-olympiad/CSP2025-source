#include<bits/stdc++.h>
using namespace std;
int n,num=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n,cmp);
	if(n==3)
		if(a[1]<a[1]+a[2]+a[3])
		num=1;
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
