#include<bits/stdc++.h>
using namespace std;
int score[150];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	scanf("%d%d",&n,&m);
	int x=n*m;
	for(int i=0;i<x;i++){
		scanf("%d",&score[i]);
	}
	int r=score[0];
	sort(score,score+x,cmp);
	int hang=1;
	int lie=1;
	int forward=0;
	for(int i=0;i<x;i++){
		if(forward==0){
			if(score[i]==r){
				printf("%d %d",lie,hang);
			}else{
				if(hang==n){
					lie++;
					forward=1;
				}else {
					hang++;
				}
			}
				
		}else if(forward==1){
			if(score[i]==r){
				printf("%d %d",lie,hang);
			}else{
				if(hang==1){
					lie++;
					forward=0;
				}else{
					hang--;
				}
			}
		}
	}	
	return 0;
}
