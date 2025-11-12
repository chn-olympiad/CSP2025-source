#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,cnt;
ll x[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
        scanf("%d",&x[i]);
	}
	ll l=1,r=1,sum=x[1];
	while(r<=n){
        while(r+1<=n){
            if(sum==k) break;
            sum=sum^x[++r];
        }
        if(r>n&&sum!=k){
            break;
        }
        if(sum==k){
            cnt++;
            l=r+1;
            r=l;
            sum=x[l];
        }else{
            l++;
            r=l;
            sum=x[l];
        }
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


