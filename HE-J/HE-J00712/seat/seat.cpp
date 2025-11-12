#include<bits/stdc++.h>
using namespace std;
bool flag=0;//ton[105]={0},
int n,m,x,y,mm,bao,sum;
int a[105]={0};
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	mm=n*m;x=1;y=1;
	for(int i=1;i<=mm;i++){
		cin>>a[i];
	}
	bao=a[1];
	sort(a+1,a+1+mm,cmp);
	for(y=1;y<=m;y++){
		if(y%2==1){
			for(x=1;x<=n;x++){
				int num=(y-1)*n+x;
				if(a[num]==bao){
					flag=1;
				}
				if(flag) break;
			}
		}else{
			for(x=n;x>=1;x--){
				int num=(y-1)*n+(++sum);
				if(a[num]==bao){
					flag=1;					
				}
				if(flag) break;
			}
			sum=0;
		}
		if(flag) break;
	}
	cout<<y<<" "<<x;
	return 0;
}
