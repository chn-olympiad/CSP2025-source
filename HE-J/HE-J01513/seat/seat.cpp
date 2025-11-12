#include<bits/stdc++.h>
using namespace std;
int n,m;
int wtf,paiming,hang,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int score[n*m];
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	wtf=score[0];
	sort(score,score+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(score[i]==wtf){
			paiming=n*m-i;
			break;
		}
	}
	if(paiming%n!=0){
		lie=paiming/n+1;
	}else{
		lie=paiming/n;
	}//处理列 
	if(lie%2==0){
		hang=n+1-(paiming-(lie-1)*n);
	}
	if(lie%2==1){
		hang=paiming-(lie-1)*n;
	}//处理行 
	cout<<lie<<" "<<hang;
	return 0;
} 
