#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	//cout<<k<<" ";
	//2 5
	//52 12 14 24 41 51 410 17 9 1423
	//cout<<k<<" ";
	if(k>n){
		if(k%n==0){
			c=k/n;
			if((k/n)%2!=0){//yes
				r=k/n-1;
			}
			else{//yes
				r=n+1-k/n;
			}
		}
		else{//yes
			int z=k%n;
			c=k/n+1;
			if((k/n)%2==0){
				r=z;
			}
			else{
				r=n+1-z;
			}
		}
	}
	else{//yes
		c=1;	
		r=k;
	}
	cout<<c<<" "<<r;
	return 0;
} 
