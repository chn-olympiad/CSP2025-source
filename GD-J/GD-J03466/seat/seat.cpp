#include<bits/stdc++.h>
using namespace std;
struct sdu{
	int i,ai;
}sd[200];
int n,m;
bool cmd(sdu x,sdu y){
	if(x.ai>y.ai)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;i++){
		sd[i].i=i;
		scanf("%d",&sd[i].ai); 
	}
	sort(sd,sd+n*m,cmd);
	int pl=0;
	for(int i=0;i<n*m;i++){
		if(sd[i].i==0){
			pl=i;
			break;
		}
	}
	int gp=pl/(2*n),peo=pl%(2*n);
	int x=0,y=0;
	x+=gp*2;
	if(peo<n)y+=peo;
	else x++,y+=n-(peo%n)-1;
	x++,y++;
	cout<<x<<" "<<y;
	//cout<<pl<<"\n";
	//for(int i=0;i<n*m;i++)cout<<sd[i].ai<<" ";
	return 0;
}
