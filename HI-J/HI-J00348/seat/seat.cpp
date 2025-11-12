#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n,m;
	scanf("%d %d",&n,&m);
	long long x[m*n],s[m*n];
	for(int i=0;i<m*n;i++){
		cin>>x[i];
		s[i]=x[i];
	}sort(s,s+m*n);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(s[m*n-cnt-1]==x[0]){
					cout<<i<<" "<<j;
					return 0; 
				}cnt++;
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(s[m*n-cnt-1]==x[0]){
					cout<<i<<" "<<j;
					return 0; 
				}
				cnt++;
			}
		}
	}
	return 0;
}

