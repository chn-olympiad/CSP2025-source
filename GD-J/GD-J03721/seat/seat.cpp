#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,cnt;
struct score{
	int num,sco;
}x[100001];
bool cmp(score i,score j){
	return i.sco>j.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>x[i].sco;
		x[i].num=i;
	}
	sort(x+1,x+1+n*m,cmp);
	cnt=1;
	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=m;j++){
				if(x[cnt].num==1){
					cout<<i<<" "<<j;
					return 0;
				}
				else{
					cnt++;
				}
			}
		}
		else{
			for(j=m;j>=1;j--){
				if(x[cnt].num==1){
					cout<<i<<" "<<j;
					return 0;
				}
				else{
					cnt++;
				}
			}
		}
	}
	
	return 0;
} 
