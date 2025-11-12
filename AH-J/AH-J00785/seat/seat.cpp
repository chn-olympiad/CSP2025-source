#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int n,m;
int s[15][15],gs[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x=1,y=1,f1=1,sum;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
		scanf("%d",&gs[i]);
	    if(i==1) sum=gs[i];
	}
	sort(gs+1,gs+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		s[x][y]=gs[i];
		if(x==n&&f1==1){
			y++;
		    f1=0;
		}
		else if(x==1&&f1==0){
			y++;
			f1=1;
		}
		else if(f1==1&&x<n) x++;
		else if(f1==0&&x>1) x--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==sum){
				cout<<j<<" "<<i;
			    break;
			}
		}
	}
    return 0;
}
