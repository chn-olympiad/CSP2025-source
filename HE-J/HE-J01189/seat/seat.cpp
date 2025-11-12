#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200];
map<int,bool> maa;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	maa[a[1]]=true;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(maa[a[i]]){
			cout<<(i-1)/n+1<<" ";
			if((i-1)/n%2==0){
				cout<<(i-1)%n+1;
			}else{
				cout<<n-(i-1)%n;
			}
			return 0;
		}
		
	}
	return 0;
}
