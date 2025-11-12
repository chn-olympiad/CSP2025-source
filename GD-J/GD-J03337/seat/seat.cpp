#include<bits/stdc++.h>
using namespace std;
int n,m,flag,t;
int a[15][15],vis[110],h[15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	t = n*m;
	for(int i=1;i<=t;i++){
		cin >> vis[i];
	}
	flag = vis[1];
	sort(vis+1,vis+t+1,cmp);
	int l=1,r=n;
	for(int i=1;i<=10;i++){
		if(flag<=vis[l]&&flag>=vis[r]){
			if(i%2==0){
				int c=n;
				for(int j=l;j<=r;j++){
					if(vis[j]==flag){
						cout << i << ' ' << c;
						break;
					}
					c--;
				}
			}else{
				int c=1;
				for(int j=l;j<=r;j++){
					if(vis[j]==flag){
						cout << i << ' ' << c;
						break;
					}
					c++;
				}
			}
			break;
		}
		l+=n;
		r+=n;
	}
	return 0;
}
