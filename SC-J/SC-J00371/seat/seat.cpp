#include<bits/stdc++.h>
using namespace std;
int n,m;
int seats[12][12];
int scores[102];
bool cmp(int a,int b){
	return a>b;
}
int r1,r2;
void f(int a){
	int i=0,j,iii=0;
	for(j=0;j<m;j++){
		if(j%2==0){
			for(;i<n;i++){
				seats[i][j]=scores[iii];
				iii++;
				if(seats[i][j]==a){
					r1=j+1,r2=i+1;
					return;
				}
			}
			i--;
		}
		else{
			for(;i>=0;i--){
				seats[i][j]=scores[iii];
				iii++;
				if(seats[i][j]==a){
					r1=j+1,r2=i+1;
					return;
				}
			}
			i++;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int aaa=0;
	cin>>n>>m;
	memset(scores,-1,sizeof(scores));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>scores[aaa];
			aaa++;
		}
	}
	int temp=scores[0];
	sort(scores,scores+aaa,cmp);
	f(temp);
	cout<<r1<<' '<<r2;
	return 0;
}