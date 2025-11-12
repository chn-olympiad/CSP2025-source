#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N];
bool cmp(int x,int y){
	return x<y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==1||n==2) cout<<0;
	else{
		if(((a[1]+a[2])>a[3])&&((a[3]-a[2])<a[1])&&((a[3]-a[1])<a[2])){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
