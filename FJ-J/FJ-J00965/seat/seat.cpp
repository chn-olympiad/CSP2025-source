#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,score[10001],xr,nx=1,ny=1,flag=0;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>score[i];
		xr=score[1];
	}
	sort(score+1,score+1+x*y,cmp);
	for(int i=1;i<=x*y;i++){
		if(score[i]==xr){
			cout<<nx<<' '<<ny;
			return 0;
		}
		if(flag==0){
			ny++;
			if(ny>y){
				flag=1;
				ny=y;
				nx++;
			}
		}else{
			ny--;
			if(ny<1){
				flag=0;
				ny=1;
				nx++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
