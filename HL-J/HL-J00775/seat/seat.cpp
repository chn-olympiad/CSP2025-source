#include <bits/stdc++.h>
using namespace std;
long long a[10001];
long long n,m,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	cin>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(long long i=2;i<=m*n;i++){
		for(long long j=i;j>1;j--){
			if(a[j]>a[j-1]){
				if(j==cnt){
					cnt--;
				}else if(j-1==cnt){
					cnt++;
				}
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	if(cnt==1){
		cout<<"1 1";
	}else{
		long long h=0,l=0;
		if(cnt%n==0){
			l=cnt/n;
		}else{
			l=cnt/n+1;
		}
		if(l%2==0){
			if(cnt%n==0){
				h=1;
			}else{
				h=(n+1)-(cnt%n);
			}
		}else{
			if(cnt%n==0){
				h=n;
			}else{
				h=cnt%n;
			}
		}
		cout<<l<<" "<<h;;
	}
	return 0;
}