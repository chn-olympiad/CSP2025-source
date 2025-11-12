#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	int n=0,m=0,r=0,p=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		}
	r=a[1];
	for(int j=1;j<=n*m;j++){
		for(int x=j;x<=n*m;x++){
			if(a[j]<a[x]){
				swap(a[x],a[j]);
				}
			}
		}
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			}
		}
	if(p%m==0)
	{
		cout<<p/m<<" "<<m;
	}
	else{
		cout<<p/m+1<<" "<<p%m;
		}
	return 0;
}
