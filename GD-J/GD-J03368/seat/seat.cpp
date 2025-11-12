#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			sum=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(sum<=n*i){
			if(i%2==1){
				cout<<i<<" "<<sum-m*(i-1);
				return 0;
			}
			else{
				cout<<i<<" "<<m-sum+m*(i-1)+1;
				return 0;
			}
		}
	}
	return 0;
}
