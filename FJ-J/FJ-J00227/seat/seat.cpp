#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[111];

bool cmp(int a,int b){
	if(a<b){
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int s=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[n*(i-1)+j]==s){
				if(i%2==0){
					cout<<i<<" "<<n-j+1;
				}else{
					cout<<i<<" "<<j;
				}
				
			}
		}
	}
	return 0;
}
