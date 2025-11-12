#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,a[111],l,p,u,w;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l++;
			cin>>a[l];
		}
	}
	p=a[1];
	sort(a+1,a+1+l,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				u++;
				if(a[u]==p){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				u++;
				if(a[u]==p){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		if(a[i]==p){
//			u=i;
//			break;
//		}
//	}
//	if(u%n){
//		if((u/n)%2==0){
//			cout<<u/n+1<<' '<<u%n;
//		}else{
//			cout<<u/n+1<<' '<<n-u%n+1;
//		}
//	}else{
//		if((u/n)%2==0){
//			cout<<u/n<<' '<<1;
//		}else{
//			cout<<u/n<<' '<<n;
//		}
//	}
	return 0;
}

