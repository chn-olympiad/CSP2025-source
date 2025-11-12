#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[1010];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			int q=i%n,p=i/n;
			if(q==0){
				if(p%2==0)
					cout<<p<<" "<<n-q+1;
				else
					cout<<p<<" "<<n;
			}
			else{
				if(p%2==0)
					cout<<p+1<<" "<<q;
				else
					cout<<p+1<<" "<<n-q+1;
			}
		}
	return 0;
}

