#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum,id;
}a[110];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,cnt=1;
	while(cnt<=n*m){
		if(a[cnt].id==1){
			cout<<j<<" "<<i,exit(0);
		}
		if(j%2==0){
			if(i>1){
				i--;
			}
			else{
				j++;
			}
		}
		else{
			if(i<n){
				i++;
			}
			else{
				j++;
			}
		}
		cnt++;
	}
	return 0;
}