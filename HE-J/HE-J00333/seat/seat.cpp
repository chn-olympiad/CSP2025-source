#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=147;
int a[N*N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int t,up=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)t=a[i];
		else if(a[i]>t)up++;
	}
	int l=1,h=1,j=1;
	bool f=0;
	while(j<up){
		if(j==up)break;
		if(h<n&&f==0){
			h++;
			j++;
		}
		else if(h>1&&f==1){
			h--;
			j++;
		}
		else if(h==n&&l%2==1){
			l++;
			f=1;
			j++;
		}
		else if(h==1&&l%2==0){
			l++;
			j++;
			f=0;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
