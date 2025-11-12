#include<bits/stdc++.h>
using namespace std;
int score[150],a[100][100];
bool cmp(int a_,int b_){
	return a_>b_;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>score[i];
	int ans=score[1];
	sort(score+1,score+1+n*m,cmp);	
	int i=1,j=1,k=1,all=n*m,d=0;//·½Ïòd 
	while(all--){
		a[i][j]=score[k];
		if(score[k]==ans){
			cout<<i<<" "<<j;
			break;
		}
		k++;
		if(!d){
			if(j<m)j++;
			else {
				i++;
				d=1;
			}
		}
		else{
			if(j>1)j--;
			else{
				i++;
				d=0;
			}
		}
	}	
//	for(int i=1;i<10;i++){
//		for(int j=1;j<=10;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}

