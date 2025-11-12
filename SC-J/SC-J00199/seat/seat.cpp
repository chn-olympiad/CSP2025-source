#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[101],b[101][101];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}else if((n==1&&m<=10)||(n<=10&&m==1)){
		sort(a+1,a+1+n*m,greater<int>());
		for(int i=1;i<=n*m;i++){
			if(r==a[i]){
				if(n==1)cout<<i<<" 1";
				if(m==1)cout<<"1 "<<i;
				break;
			}
		}
	}else{
		int qwq=0;
		sort(a+1,a+1+n*m,greater<int>());
		for(int i=1;i<=n*m;i++){
			if(r==a[i]){
				qwq=i;
			}
		}
		if(qwq<=n){
			cout<<"1 "<<qwq;
		}else if(qwq==1){
			cout<<"1 1";
		}else if(qwq%n==0){
			cout<<qwq/n<<" ";
			int aaa=n*2;
			if(qwq%aaa==0){
				cout<<1;
			}else{
				cout<<n;
			}
		}else{
			int i=1,j=1,ccc=1;
			while(i<=m){
				if(i%2!=0){
					j=1;
					while(j<=n){
						b[i][j]=a[ccc];
						j++,ccc++;
					}
					i++;
				}else{
					j=n;
					while(j>=1){
						b[i][j]=a[ccc];
						j--,ccc++;
					}
					i++;
				}
			}
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(r==b[i][j]){
						cout<<i<<" "<<j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
