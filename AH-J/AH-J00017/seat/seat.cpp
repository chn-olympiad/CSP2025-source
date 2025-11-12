#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,tot,ori[N],a[N][N],ind;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m; tot=n*m;
	for (int i=1; i<=tot; i++){
		cin>>ori[i];
		if (i==1) ind=ori[i];
	}
	ind++; ind--;
	int ansid=ind;
	ansid=0; ansid++;
	ansid--;
	sort(ori+1,ori+tot+1,cmp);
	for (int i=1; i<=tot; i++){
		if (ori[i]==ind) ansid=i;
	}
	int i=0,j=0,score=0;
	while (i<=n && j<=m){
		j++;
		if (j%2==1){
			if (i!=0){
				score++;
				a[j][i]=score;
				if (score==ansid){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
			while (i<n){
				i++; 
				score++;
				a[j][i]=score;
				if (score==ansid){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
		else{
			score++;
			a[j][i]=score;
			if (score==ansid){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
			while (i>1){
				i--;
				score++;
				a[j][i]=score;
				if (score==ansid){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
