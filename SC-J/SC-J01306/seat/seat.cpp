#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int ppp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	int n,m,w,cnt=0; 
 	cin>>n>>m;
 	int c,r;
 	for(int i=1;i<=n*m;i++){
 		cin>>a[i];
	}int R=a[1];
	sort(a+1,a+n*m+1,ppp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			w=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cnt++; 
				if(cnt==w){
					c=i;
					r=j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
			if(cnt==w){
				
					c=i;
					r=j;
					break;
				}
			}
		}
		
	}
	cout<<c<<" "<<r;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	return 0;
}