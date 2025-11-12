#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=110;
int n,m;
struct node{
	int score,num;
}a[MAXN];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].score;
		a[i].num=i; 
	}	 
	sort(a+1,a+k+1,cmp);
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[p++].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>0;j--){
				if(a[p++].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//9:00 finished,qi wang de fen 100pts.
