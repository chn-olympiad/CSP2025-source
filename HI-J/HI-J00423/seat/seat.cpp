#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m;
bool soc(long long i,long long l){
	return i>l;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; long long o=1;
	for(long long i=1;i<=n;i++){
		for(long long l=1;l<=m;l++){
			cin>>a[o]; o++;
		}
	}long long RR=a[1];
	sort(a+1,a+1+o,soc);
	long long k=1;
	for(long long i=1;i<=n;i++){
		long long j=m;
		for(long long l=1;l<=m;l++){
			if(a[k]==RR){
				if(n%2==1){
					printf("%d %d",i,l);
					return 0;
				}else{
					printf("%d %d",i,j);
					return 0;
				}
			}k++;j--;
		}
	}
	
	return 0;
} 
