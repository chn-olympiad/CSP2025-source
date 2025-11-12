#include<bits/stdc++.h>
using namespace std;
int p[102],w[102];
bool cmp(int a,int b){
		return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
	}
	int cnt=p[1];
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)w[p[i]]=i;
	int h,l,mo=w[cnt]%n;
	if(mo!=0)l=w[cnt]/n+1;
	else l=w[cnt]/n,mo=n;
	if(l%2==0)h=n-mo+1;
	else h=mo;
	//cout<<cnt<<' '<<mo<<' '<<w[cnt]<<' ';
	cout<<l<<' '<<h;
	return 0;
}//wxjwxjwxjxwjxwjxwjxwjxwjxwjwxjwxjwxjwxj
