#include<bits/stdc++.h>
using namespace std;
int n,m,sc;//sc是小明的成绩 
int cj[103];//成绩 
int h=0,l=1,tmpi; 
bool jo=true;//true是向下走，false是向上走 
void px(int x,int y){
	for(int i=y;i>=x;i--){
		tmpi=i;
		while(cj[tmpi]>cj[tmpi-1]&&tmpi>1){
			int tmp=cj[tmpi-1];
			cj[tmpi-1]=cj[tmpi];
			cj[tmpi]=tmp;
			tmpi--;
		}
		px(tmpi+1,n*m);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&cj[i]);
	}
	sc=cj[1];
	px(1,n*m);
	for(int i=1;i<=n*m;i++){
		if(jo) h++;
		else h--;
		if(h==n+1){
			l++;
			h--;	
			jo=!jo;
		}
		if(h==0){
			l++;
			h++;	
			jo=!jo;
		}
		if(cj[i]==sc){
			cout<<l<<" "<<h;
			break;
		} 
	}
	return 0;
} 
