#include <bits/stdc++.h>
using namespace std;
int n,m;
struct grd{
	int cj;
	bool isr;
}grade[105];
bool cmp(grd a,grd b){
	return a.cj>b.cj;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	grade[1].isr=true;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i].cj;
	}
	int maxn=n*m;
	sort(grade+1,grade+maxn+1,cmp);
	int flag=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				flag++;
				if(grade[flag].isr==true){
					cout<<i<<" "<<j<<endl;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				flag++;
				if(grade[flag].isr==true){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	return 0;
}