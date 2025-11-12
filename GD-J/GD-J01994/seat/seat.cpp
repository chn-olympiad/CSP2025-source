#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	int cnt=0,sum=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==q){
			cnt=n*m-i+1;
			break;
		}
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j<<"\n";
					f=1;
					break;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j<<"\n";
					f=1;
					break;
				}
			}
		}
		if(f)break;
	}
	return 0;
}

