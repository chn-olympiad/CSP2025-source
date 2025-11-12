#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1011010]={},cnt,ui=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i+=1){
		cin>>a[i];
		if(i==1) cnt=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i+=1){
		if(i%2==0){
			for(int j=n;j>=1;j-=1){
				//cout<<a[ui]<<" "<<i<<" "<<j<<endl;
				if(a[ui]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				ui+=1;
			}
		}else{
			for(int j=1;j<=n;j+=1){
				//cout<<a[ui]<<" "<<i<<" "<<j<<endl;
				if(a[ui]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				ui+=1;
			}
		}
		
	}
	return 0;
}

