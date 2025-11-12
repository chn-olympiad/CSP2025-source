#include"bits/stdc++.h"
using namespace std;
struct node{
	int score,id;
	bool operator <(const node &a) const {
		return score>a.score;
	}
};
node a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int i=1,j=1;
	int cnt=1;
	bool to=true;//true v false ^
	while(j<=m){
		if(to){
			while(i<=n){
				if(a[cnt].id==1){
					printf("%d %d\n",j,i);
					return 0;
				}
				cnt++;
				i++;
			}
			i=n;
		}
		else{
			while(i>=1){
				if(a[cnt].id==1){
					printf("%d %d\n",j,i);
					return 0;
				}
				cnt++;
				i--;
			}
			i=1;
		}
		j++;
		to=!to;
	}
	return 0;
}
