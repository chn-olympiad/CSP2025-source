#include<bits/stdc++.h>
using namespace std;

int s[105];
int vis[15][15];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n*m;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	int b=s[1];
	sort(s+1,s+a+1,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				vis[i][j]=s[cnt];
				cnt+=1;
			}
		}else{
			for(int j=m;j>0;j--){
				vis[i][j]=s[cnt];
				cnt+=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]==b){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
