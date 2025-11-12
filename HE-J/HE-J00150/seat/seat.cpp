#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m,q=0;
	int a[n+1][m+1],m1[s];
	for(int i=0;i<=s-1;i++){
//		cin>>m1[i];
		scanf("%d",&m1[i]);
	}
	for(int i=0;i<=s-1;i++){
		for(int j=i+1;j<=s-1;j++){
			int w=0;
			if(m1[i]<m1[j]){
				w=m1[i]+m1[j];
				m1[i]=w-m1[i];
				m1[j]=w-m1[j];
				if(i==q){
					q=j;
				}
				else if(j==q){
					q=i;
				}
			}
		}
	}
	int h=q%m,l=q/m;
	cout<<l+1<<" "<<h+1;
	return 0;
}
