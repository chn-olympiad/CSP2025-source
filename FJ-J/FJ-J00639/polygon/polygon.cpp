#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,a[N*5+5],x,D[N*5+5],E[N*5+5],cnt=1,lastjieshu,cnti;
string A,B,Adao,Bdao,C;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=0;
			for(int k=j;k<=i;k++){
				sum+=a[k];
			}
			if(a[i]*2<=sum)cnt++;
		}
	}
	cout<<cnt;
	return 0;
	
	
}
 
