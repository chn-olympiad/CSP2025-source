#include <bits/stdc++.h>
using namespace std;

int n,m,exam[1008],seats[108][108],p,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int tot=n*m;
	for(int i=1;i<=tot;i++) cin >> exam[i];
	k=exam[1];
	sort(exam+1,exam+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(exam[i]==k){
			p=i;
			break;
		}
	}
	int x=0,y=1,flag=1;
	for(int i=1;i<=tot;i++){
		if(i%n==1&&i!=1){
			y++;
			flag*=-1;
		}else x+=flag;
		seats[x][y]=exam[i];
		if(i==p){
			cout << y << " " << x;
			break ; 
		}
	}
	return 0;
}

