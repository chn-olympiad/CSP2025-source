#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[541880];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int num=0;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
	if(a[1]==a[i]){
		sum=a[1]+a[i];
		break;
	}	
	}
	for(int i=1;i<=n;i++){
		if(sum>0){
			if(sum<a[i]){
				num++;
			}
		}
	}
	if(sum>0) cout<<num+n-1;
	if(sum==0) cout<<n*2-1;
	return 0;
}
