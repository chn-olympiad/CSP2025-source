#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s,ans,cnt;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	long long len=n*m;
	sort(a+1,a+len+1,cmp);
	for(long long i=1;i<=len;i++){
		if(a[i]==s){
			ans=i;
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			cnt++;
			if(cnt==ans){
				cout<<i<<" ";
				if(i%2==0) cout<<m-j+1;
				else cout<<j;
				return 0;
			}
		}
	}
	return 0;
}

