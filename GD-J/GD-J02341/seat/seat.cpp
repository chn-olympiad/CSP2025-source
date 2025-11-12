#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int b[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long sum=n*m;
	int se;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}
	se=b[1];
	sort(b+1,b+sum+1);
	int jx; 
	for(int i=1;i<=sum;i++){
		if(b[i]==se){
			jx=sum+1-i;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				a[j][i]=cnt;
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				a[j][i]=cnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==jx){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	
	return 0;
}
