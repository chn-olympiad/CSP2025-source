#include<bits/stdc++.h>
using namespace std;
int sum[10000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sum[i];
	}
	q=sum[1];
	sort(sum+1,sum+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sum[i]==q){
			q=i;
			break;
		}
	}
	if(q==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int i,j;
	for(i=1;i<=m;i++){
		if(i%2==1){
			j=1;
			for(int p=1;p<=n;p++){
				j++;
				q--;
				if(q==0){
					if(j==1){
						cout<<i-1<<" "<<j;
						return 0;
					}else{
						cout<<i<<" "<<j-1;
						return 0;
					}
				}
			}
		}else if(i%2==0){
			j=n;
			for(int p=1;p<=n;p++){
				j--;
				q--;
				if(q==0){
					if(j==1){
						cout<<i<<" "<<n;
						return 0;
					}else{
						cout<<i<<" "<<j-1;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
