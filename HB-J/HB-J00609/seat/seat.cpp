#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[50][50],px[10000],cj;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>px[i];
	}
	cj=px[0];
	sort(px,px+n*m,cmp);
	int i=0,j=1;
	for(int s=1;s<=n*m;s++){
		if(px[s]==cj){
			cout<<i+1<<" "<<j+1;
			return 0;
		}
		cout<<i<<" "<<j;
		if(i==n){
			j++;
			continue;
		}
		else if(i==1&&j>1){
			j++;
			continue;
		}
		if(j%2==0){
			j--;
			continue;
		}
		else if(i%2==1){
			j++;
			continue;
		}
		
		
	}
		
	return 0;
}
