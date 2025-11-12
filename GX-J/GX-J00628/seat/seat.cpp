#include <bits/stdc++.h>
using namespace std;
int b[410];
int m,n,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
		cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+(m*n)+1,cmp);
    for(int i=1;i<=m*n;i++){
		if(b[i]==x){
			y=i;
			break;
		}
    }
    for(int i=1;i<=n;i++){
		int ans=m*i;
		if(ans>=y){
			if(i%2==1){
				cout<<i<<' '<<n-(ans-y);
				return 0;
			}
			else{
				cout<<i<<' '<<1+(ans-y);
				return 0;
				
			}
		}
	}
    return 0;
}
