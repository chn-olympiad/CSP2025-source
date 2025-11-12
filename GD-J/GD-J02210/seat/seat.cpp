#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int x=i;
			int ans1=(x-1)/n;
			int ans2=0;
			if(ans1%2==0){
			    ans2=(x-1)%n+1;	
			}
			else{
				ans2=n-(x-1)%n;
			}
			ans1++;
			cout<<ans1<<' '<<ans2;
			return 0;
		}
	}
	return 0;
}
