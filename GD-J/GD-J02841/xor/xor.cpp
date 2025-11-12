#include<bits/stdc++.h>
#define N 500005
using namespace std;

int n,m;
int a[N];
int d[N];

int ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)d[i]=d[i-1]^a[i];
	
//	for(int i=1;i<=n;i++)cout<<d[i]<<" ";
//	cout<<endl;
	
	for(int i=1,j=0;i<=n;i++){
//		if(a[i]==m){
//			ans++;
//			
////			cout<<i<<endl;
//			
//			j=i;
//			continue;
//		}
		for(int k=j;k<i;k++){
			int l=d[i]^d[k];
			if(l==m){
				ans++;
				
//				cout<<i<<" "<<d[i]<<" "<<k<<" "<<d[k]<<" "<<l<<endl;
				
				j=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
4 2
2 1 0 3

2
*/

/*
4 3
2 1 0 3 

2
*/

/*
4 0
2 1 0 3

1
*/

/*
30 0
1 3 4 8 5 7 6 6 8 9 6 5 4 6 5 7 8 6 6 8 9 7 7 7 9 9 9 0 3 4

*/
