#include<bits/stdc++.h>
using namespace std;
int a[114514];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m>>a[1];
	int q=a[1],s;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==q)s=i;
	int k;
	if(s%m!=0)k=s/m+1,cout<<k<<" ";
	else k=s/m,cout<<k<<" ";
	if(s%m==0){cout<<m;return 0;}
	if(k%2==0){
		cout<<m+1-s%m;
		return 0;
	}
	if(k%2!=0)cout<<s%m;
	return 0;
}
