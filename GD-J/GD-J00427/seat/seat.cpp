#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,a[15][15],score[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//T2
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int R=score[1];
	sort(score+1,score+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=score[cnt];
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=score[cnt];
				cnt++;
			}
		}
		
	}
	//for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
} 
