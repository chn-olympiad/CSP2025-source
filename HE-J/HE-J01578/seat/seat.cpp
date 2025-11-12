#include<bits/stdc++.h>
using namespace std;
int n,m,l[102],lr;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>l[i];
	}
	lr=l[1];
	sort(l+1,l+1+n*m,cmp);
	int x=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			int j=1;
			while(j<=n){
				if(l[x]==lr){
					cout<<i<<' '<<j;
					x++;
					j++;
					break;
				}
				j++;
				x++;
			}
		}else{
			int j=n;
			while(j>=1){
				if(l[x]==lr){
					cout<<i<<' '<<j;
					x++;
					j--;
					break;
				}
				j--;
				x++;
			}
		}
	}
	return 0;
}
