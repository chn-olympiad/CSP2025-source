#include<bits/stdc++.h>
using namespace std;
int a[10010];
	int k=1;
	int xh=0;
	int n,m;
	int xxxx=0;
	int yyyy=0;
	int num=0;
bool cmp(int x,int y){
	return x>y;
}
void cha(int x,int y,int yii,int fxx){
//fxx=0 =>xia
//fxx=1 =>shang
	if(yii==xh){
		xxxx=x;
		yyyy=y;
		return ;
	}
	if(x==n && y==m){
		return ;
	}
	if(fxx==0){
		if((y+1)>m){
			cha(x+1,y,yii+1,1);
		}
		else{
			cha(x,y+1,yii+1,0);
		}
	}
	if(fxx==1){
		if((y-1)<1){
			cha(x+1,y,yii+1,0);
		}
		else{
			cha(x,y-1,yii+1,1);
		}
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		cin>>a[k];
		if(i==1 && j==1){
			num=a[k];
		}
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==num){
			xh=i;
		}
	}
	cha(1,1,1,0);
	cout<<xxxx<<" "<<yyyy;
	return 0;
}
