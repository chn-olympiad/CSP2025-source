#include<bits/stdc++.h>
using namespace std;
int a[20][20][5];
int mp[110];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>mp[i];
	int R=mp[1];
	sort(mp+1,mp+n*m+1,cmp);
	int r;
	for(int i=1;i<=n*m;i++){
		if(mp[i]==R){
			r=i;break;
		} 
	}
	for(int i=1;i<=n;i++){
		int j=0;
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j][1]=j;a[i][j][2]=i;
			}
		}
		else{
				int k=m;
				for(int j=1;j<=m;j++){
					a[i][j][1]=k;a[i][j][2]=i;
					k--;
				}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			if(cnt>=r){
				cout<<a[i][j][2]<<" "<<a[i][j][1];return 0; 
			}
		}
	}
	return 0;	
}
