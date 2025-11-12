#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000]={0},sum=0;
bool check(int i,int j){
	if(j-i<1)return 0;
	int summ=0;int maxx=-1;
	for(int k=i;k<=j;k++){
		summ+=a[k];
		maxx=max(maxx,a[k]);
	}
	if(summ>(maxx*2))return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)){
				sum++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<sum;
	return 0;
}
