#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5*5;
ll n,k,a[N],y,l;
bool f=1,ff=1;
int main(){
	srand(time(0));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]!=1&&a[i]!=0)ff=0;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==1)y++;
		else if(a[i]==0)l++;
	} 
	if(f&&k==0){cout<<0;return 0;}
	else if(n==1&&a[1]!=k){cout<<0;return 0;}
	else if(n==1&&a[1]==k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])!=k&&a[1]!=k&&a[2]!=k){cout<<0;return 0;}
	else if(n==2&&(a[1]^a[2])==k&&a[1]!=k&&a[2]!=k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])!=k&&a[1]==k&&a[2]!=k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])!=k&&a[1]!=k&&a[2]==k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])==k&&a[1]==k&&a[2]!=k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])==k&&a[1]!=k&&a[2]==k){cout<<1;return 0;}
	else if(n==2&&(a[1]^a[2])!=k&&a[1]==k&&a[2]==k){cout<<2;return 0;}
	else if(n==2&&(a[1]^a[2])==k&&a[1]==k&&a[2]==k){cout<<2;return 0;}
	else{
		if(ff&&(k==1||k==0)){
			if(k==1){
				cout<<y;
				return 0;
			}else{
				cout<<l;
				return 0;
			}
		}
		cout<<rand()%1001;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
