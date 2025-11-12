#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[105],num,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	cout<<num/n+1<<" ";
	num++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num--;
			if(num==0){
				if(i%2==1){
					cout<<j;
				}
				else 
				{
					cout<<m-j+1;
				}
				return 0;
			}
		}
	}
	return 0;
}

