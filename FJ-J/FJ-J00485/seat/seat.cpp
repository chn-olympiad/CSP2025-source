#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,ans,cnt,p,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(ans==a[i]){
			cnt=n*m-i+1;
			break;
		}
	}
	l=cnt/n;
	if(cnt%n>0) l++;
	p=cnt-(l-1)*n;
	if(l%2==0){
		p=n-p+1;
	}
	cout<<l<<" "<<p;
	return 0;
} 
