#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;
int rs;
int maxn=0;
int a[205];


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s;
		if(i==1)rs=s;
		if(s>maxn)maxn=s;
		a[s]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;){
			if(a[maxn]!=0){
				if(maxn==rs){
					if(i%2==0)cout<<i<<" "<<(n+1)-j;
					if(i%2!=0)cout<<i<<" "<<j;
					return 0;
				}
				j++;
			}
			maxn--;
		}
		
	}





	return 0;
}
