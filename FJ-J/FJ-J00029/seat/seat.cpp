#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int main(){
    freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
    	cin>>a[i];
	}
	int num=0;
	int ans=a[1];
	sort(a+1,a+k+1);
	if(ans==a[k]){
		cout<<n<<' '<<m;
		return 0;
	}
	for(int i=k;i>=1;i--){
		if(a[i]==ans){
			num=k-i+1;
			break;
		}
	}
	int tx=0;
	int ty=0;
	for(int i=1;i<=m;i++){
		if(i*n>=num){
		    tx=i;
		    break;
		}
	}
	if(tx%2!=0){
		ty=num-((tx-1)*n);
	}else if(tx%2==0){
		ty=n-(num-((tx-1)*n))+1;
	}
	cout<<tx<<' '<<ty;
	return 0;
}
