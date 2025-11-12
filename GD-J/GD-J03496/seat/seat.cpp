#include<bits/stdc++.h>
using namespace std;
#define FILE "seat"
int n,m;
pair<int,int> a[1001];
int id[101][101];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	cin >> n >> m;
	int ncnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[++ncnt].first;
			a[ncnt].second=ncnt;
		}
	}
	sort(a+1,a+ncnt+1,greater<pair<int,int>>());
	int ii=0;
	for(int i=1;i<=ncnt;i++){
		if(a[i].second==1){
			ii=i;
			break;
		}
	}
	int ccnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				id[i][j]=++ccnt;
			}
		} else{
			for(int i=n;i>=1;i--){
				id[i][j]=++ccnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(id[i][j]==ii){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
/*
I want to shang mi huo xing wei da shang
//freopen("joker.in","r",stdjoker);
//freopen("sea.in","r",stdhaitai)//hai de wei dao, wo zhi dao 
//freopen("output.out","w",NeverGonnaGiveYouUp);
Arknights
Honkai: Star Rail
*/
