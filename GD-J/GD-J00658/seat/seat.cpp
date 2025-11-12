#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,mut,i,j,ans,cnt=1,a[10007],x[10007];
bool flag = true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	mut = a[1];
	sort(a,a+n*m+1);
	for(ll i = 1,j=n*m;i<=n*m;i++,j--){
		x[i] = a[j];
	}
	for(ll i = 1;i<=n*m;i++){
		if(x[i]==mut)ans = i;
	}
	i = 1;j = 1;
	while(i<=n){
		if(cnt==ans){
			cout<<i<<" "<<j;return 0;
		}
		
		if(j==n&&flag==true){
			flag = false;
			i++;
			cnt++;
		}
		else if(j==1&&flag==false){
			flag = true;
			i++;
			cnt++;
		}
		else if(flag){
			j++;
			cnt++;
		}
		else if(flag==false){
			j--;
			cnt++;
		}
		
	}
	
	return 0;
}
