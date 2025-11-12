#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[20005][4],xinfu=0,use[4],maxn=0,t,n,time1=0,b[100005],ceshi=0;
void op(ll chen){
	for(ll j=1;j<=3;j++){
		if(use[j]+1<=n/2){
			xinfu+=a[chen][j];
			use[j]++;
			if(chen==n){
				maxn=max(maxn,xinfu);
			}
			else op(chen+1);
			use[j]--;
			xinfu-=a[chen][j];
		}
	}
}
bool qwq(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t>=1;t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			if(a[i][2]==a[i][3] and a[i][2]==0){
				time1++;
			}
		}
		if(time1==n){
			sort(b+1,b+1+n,qwq);
			for(ll i=1;i<=n/2;i++){
				time1+=b[i];
			}
			cout<<time1<<endl;
		}
		else{
			use[1]=0;use[2]=0,use[3]=0;
			op(1);
			cout<<maxn<<endl;
			xinfu=0;
			maxn=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
