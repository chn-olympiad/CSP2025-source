#include<bits/stdc++.h>
using namespace std;
struct q{
	int fen;
	int student;
};
q c[105];
bool cmp(q x,q y){
	return x.fen>y.fen;
}
int xx=1,yy=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>c[i].fen;
		c[i].student=i;
	}
	sort(c,c+n*m,cmp);
	bool k=0;
	for(int i=0;i<n*m;i++){
		if(yy==n+1&&k==0){
			yy=n;
			xx++;
			k=(!k);
		}
		else if(yy==0&&k==1){
			yy=1;
			xx++;
			k=(!k);
		}
		if(c[i].student==0){
			cout<<xx<<' '<<yy;
			break;
		}
		if(k==0){
			yy++;
		}
		if(k==1){
			yy--;
		}
	}
	return 0;
}
