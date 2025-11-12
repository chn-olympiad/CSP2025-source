#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110],h=1,l=1,cnt=1;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[cnt]==x){
				cout<<l<<' '<<h;
				return 0;
			}
			if(i%2){
				if(j!=n)h++;
				else l++;
			}
			else{
				if(j!=n)h--;
				else l++;
			}
			cnt++;
		}
	}
	return 0;
}