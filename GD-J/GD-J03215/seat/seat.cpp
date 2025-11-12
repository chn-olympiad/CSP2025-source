#include<bits/stdc++.h>

using namespace std;
const int AMax=1e5+10;
int RExam;
int EveryExam[AMax];
bool cmp(int A,int B){
	return A>B;
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	scanf("%d",&RExam);
	EveryExam[0]=RExam;
	for(int i=1;i<M*N;i++){
		scanf("%d",&EveryExam[i]);
	}sort(EveryExam,EveryExam+(M*N),cmp);
	int C=1,R=1;
	int i=0;
	while(true){
		if(EveryExam[i]!=RExam){
			if(C%2!=0){
				R++;
				if(R-1==N){
					R--;
					C++;
				}
			}else {
				R--;
				if(R+1==1){
					R++;
					C++;
				}
			} 
		}else{
			printf("%d %d",C,R);
			break;
		}i++;
	}
	return 0;
}
