#include<bits/stdc++.h>
using namespace std;
int n,m;
int pe[103];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int maxn=n*m;
	for(int i=1;i<=maxn;i++){
		cin>>pe[i];
	}
	int xiaomin=pe[1];
	sort(pe+1,pe+maxn+1,cmp);
	/*for(int i=1;i<=maxn;i++){
		cout<<pe[i]<<" ";
	}
	cout<<endl<<xiaomin;*/
	//int h,l; //h为行，l为列 
	//int sh[13][13];
	int sum=0;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			sum++;
			//sh[j][i]=pe[sum];
			if(pe[sum]==xiaomin){
				cout<<i<<" "<<j;
			}
		}
		for(int j=n;j>=1;j--){
			sum++;
			//sh[j][i+1]=pe[sum];
			if((pe[sum]==xiaomin)&&i+1<=m){
				cout<<i+1<<" "<<j;
			}
		}
	}
	/*cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<sh[i][j]<<" ";
		}
		cout<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
