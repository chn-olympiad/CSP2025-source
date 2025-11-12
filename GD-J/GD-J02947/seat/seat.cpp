#include<iostream>
#include<algorithm>
using namespace std;
int score[110][110];
int a[10010];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int Max=n*m;
	for(int i=1;i<=Max;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+Max,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if((i-1)%2==0){//成绩高的在上面 
			for(int j=1;j<=m;j++){
				if(a[k++]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{//成绩高的在下面 
			for(int j=m;j>=1;j--){
				if(a[k++]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	
	return 0;
}
