#include<bits/stdc++.h>
using namespace std;
int n,m,num;//行数，列数，总人数
int R; //小R的分数 
int score[105];//分数 
bool found=false;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>score[i];
	}
	R=score[1];
	sort(score+1,score+num+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				//cout<<i<<" "<<j<<endl;
				if(R==score[k]){
					cout<<i<<" "<<j<<endl;
					found=true;
					break;
				} 
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k++;
			//	cout<<i<<" "<<j<<endl;				
				if(R==score[k]){
					cout<<i<<" "<<j<<endl;
					found=true;
					break;
				} 
			}
		}
		if(found) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
