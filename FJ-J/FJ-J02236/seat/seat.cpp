#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	ans=cnt/(2*n);
	cnt=cnt%(2*n);
	if(cnt<=n&&cnt>0) cout<<ans*2+1<<" "<<cnt;
	else if(cnt<=n&&cnt==0) cout<<ans*2<<" "<<m;
	else if(cnt>n) cout<<ans*2+2<<" "<<n-(cnt-n)+1;
	return 0;
}
