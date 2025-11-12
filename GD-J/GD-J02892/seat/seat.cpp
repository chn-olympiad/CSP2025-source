#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,b[25][25];
struct luogu{
	int x,id,pm;
}a[250];
bool cmp(luogu a,luogu b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		a[a[i].id].pm=i;
	}
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				b[i][j]=++cnt;
			}
		}
		else{
			for(int i=n;i>0;i--){
				b[i][j]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a[1].pm){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}

//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//ÒÀ¾ÉÕ©Æ­ÃÔ»óÐÐÎª 
