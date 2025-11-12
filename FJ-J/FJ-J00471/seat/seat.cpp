#include<bits/stdc++.h>
using namespace std;
bool bmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,R,mc[120],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>mc[i];
	}
	R=mc[1];
	sort(mc+1,mc+n*m+1,bmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mc[ans]<R){
				break;
			}
			if(c%2==0&&r!=1){
				r--;
			}
			else if(c%2==1&&r!=n){
				r++;
			}
			else if(r==n&&c!=m&&c%2==1){
				c++;
			}
			else if(r==1&&c%2==0&&c!=m){
				c++;
			}
			ans++;
			if(mc[ans]==R){
				cout<<c<<" "<<r;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
