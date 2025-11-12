#include<bits/stdc++.h>
using namespace std;

int n,m,tot=0,root,h=1,l=1;
int val[307];
bool vis=false;

bool cmp(const int &a,const int &b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&val[++tot]);
			if(tot==1){
				root=val[tot];
			}
		}
	}
	sort(val+1,val+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(val[i]==root){
			printf("%d %d",l,h);
			return 0;
		}else{
			if((h==n&&vis==false)||(h==1&&vis==true)){
				l++;
				vis^=1;
			}else if(vis==false){
				h++;
			}else{
				h--;
			}
		}
	}
}