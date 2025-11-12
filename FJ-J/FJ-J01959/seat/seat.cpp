#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[102];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int me=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++)
		if(a[i]==me){
			k=i;
			break;
		}
	int l=(k-1)/n+1,w=k%n;
	if(w==0)w=m;
	if(l%2)cout<<l<<" "<<w;
	else cout<<l<<" "<<m-w+1;
	return 0;
} 
