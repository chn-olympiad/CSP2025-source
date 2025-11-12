#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int tofind=arr[1],cur=1;
	sort(arr+1,arr+n*m+1,cmp);
	while(arr[cur]!=tofind)cur++;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cur--;
			if(!cur){
				if(i&1){
					cout<<i<<" "<<j;
				}else{
					cout<<i<<" "<<n-j+1;
				}
				return 0;
			}
		}
	}
	return 0;
} 
