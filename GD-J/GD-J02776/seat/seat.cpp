#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],sum[200],flag;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sum[i];
	}
	flag=sum[1];
	sort(sum+1,sum+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(flag==sum[i]){
			flag=i;
			break;
		}
	}
	int k=flag/n,kk=flag%n;
	if(kk!=0) k++;
	else kk=n;
	if(k%2==1) cout<<k<<" "<<kk;
	else cout<<k<<" "<<n-kk+1;
	return 0;
}
