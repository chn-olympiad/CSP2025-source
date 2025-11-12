#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1005][1005],n,m,b[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int xiaor=b[1],sum=1;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1,j=1;sum<=n*m;){
		a[i][j]=b[sum++];
		if(a[i][j]==xiaor){
			cout<<i<<" "<<j;
			return 0;
		}
		if(i%2==1){
			if(j<n){
				j++;
				continue;
			}
			else {
				i++;
				continue;
			}
		}
		if(i%2==0){
			if(j>1){
				j--;
				continue;
			}
			else {
				i++;
				continue;
			}
		}	
	}
	return 0;
}
//9:01 solve question 1
//9:07 try to slove question 2
//9:38 slove question 2
