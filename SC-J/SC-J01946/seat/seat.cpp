#include <bits/stdc++.h>
using namespace std;
#define N 105
bool flag;
int n,m,mp[N],g,ax,ay;
bool cmp1(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>mp[i];
	g=mp[1];
	sort(mp+1,mp+n*m+1,cmp1);
	for(int i=0;i<n;i++){
		int l=1,r=m,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(mp[i*m+mid]==g){
				flag=true;
				break;
			}
			(mp[i*m+mid]>g)?l=mid+1:r=mid;
		}if(flag){
			ax=i+1,ay=mid;
			break;
		}
	}
	if(ax%2==0)ay=m-ay+1;
	cout<<ax<<' '<<ay;
	return 0;
}