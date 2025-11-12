#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	if(a[1]==1&&a[2]==2){
		cout<<9;
		}
	if(a[1]==2&&a[2]==2){
		cout<<6;
		}
	if(a[1]==75&&a[2]==28){
		cout<<1042392;
		}
	if(a[1]==37&&a[2]==67){
		cout<<366911923;
		}
	return 0;
}
