#include<bits/stdc++.h>
using namespace std;

int t=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int zhun[t];
	int allman[t][20000][3];
	for(int i=0;i<t;i++){
		for(int j=0;j<20000;j++){
			allman[i][j][0]=0;
			allman[i][j][1]=0;
			allman[i][j][2]=0;
		}
	}
	
	for(int i=0;i<t;i++){
		cin>>zhun[i];
		for(int j=0;j<zhun[i];j++){
			cin>>allman[i][j][0]>>allman[i][j][1]>>allman[i][j][2];
		}
	}
	for(int i=0;i<t;i++){
		int pai[3][zhun[i]][2];
		for(int j=0;j<zhun[i];j++){
			if(allman[i][j][0]>=allman[i][j][1]&&allman[i][j][0]>=allman[i][j][1]&&allman[i][j][1]>=allman[i][j][2]){
				pai[0][j][0]=allman[i][j][0];
				pai[0][j][1]=0;
				pai[1][j][0]=allman[i][j][1];
				pai[1][j][1]=1;
				pai[2][j][0]=allman[i][j][2];
				pai[2][j][1]=2;
			}if(allman[i][j][0]>=allman[i][j][1]&&allman[i][j][0]>=allman[i][j][1]&&allman[i][j][2]>=allman[i][j][1]){
				pai[0][j][0]=allman[i][j][0];
				pai[0][j][1]=0;
				pai[1][j][0]=allman[i][j][2];
				pai[1][j][1]=2;
				pai[2][j][0]=allman[i][j][1];
				pai[2][j][1]=1;
			}if(allman[i][j][1]>=allman[i][j][2]&&allman[i][j][1]>=allman[i][j][0]&&allman[i][j][0]>=allman[i][j][2]){
				pai[0][j][0]=allman[i][j][1];
				pai[0][j][1]=1;
				pai[1][j][0]=allman[i][j][0];
				pai[1][j][1]=0;
				pai[2][j][0]=allman[i][j][2];
				pai[2][j][1]=2;
			}if(allman[i][j][1]>=allman[i][j][2]&&allman[i][j][1]>=allman[i][j][0]&&allman[i][j][2]>=allman[i][j][0]){
				pai[0][j][0]=allman[i][j][1];
				pai[0][j][1]=1;
				pai[1][j][0]=allman[i][j][2];
				pai[1][j][1]=2;
				pai[2][j][0]=allman[i][j][0];
				pai[2][j][1]=0;
			}if(allman[i][j][2]>=allman[i][j][1]&&allman[i][j][2]>=allman[i][j][0]&&allman[i][j][0]>=allman[i][j][1]){
				pai[0][j][0]=allman[i][j][2];
				pai[0][j][1]=2;
				pai[1][j][0]=allman[i][j][0];
				pai[1][j][1]=0;
				pai[2][j][0]=allman[i][j][1];
				pai[2][j][1]=1;
			}if(allman[i][j][2]>=allman[i][j][1]&&allman[i][j][2]>=allman[i][j][0]&&allman[i][j][1]>=allman[i][j][0]){
				pai[0][j][0]=allman[i][j][2];
				pai[0][j][1]=2;
				pai[1][j][0]=allman[i][j][1];
				pai[1][j][1]=1;
				pai[2][j][0]=allman[i][j][0];
				pai[2][j][1]=0;
			}
		}
		int ad=0,bd=0,cd=0;
		for(int j=0;j<zhun[i];j++){
			if(pai[0][j][1]==0){
				ad++;
			}if(pai[0][j][1]==1){
				bd++;
			}if(pai[0][j][1]==2){
				cd++;
			}
		}
		if(ad>(zhun[i]/2)){
			int d=ad-zhun[i]/2;
			int k[ad];
			int man=0;
			for(int j=0;j<zhun[i];j++){
				if(pai[0][j][1]==0){
					k[j]=pai[0][j][0]-pai[1][j][0];
				}
				man=man+pai[0][j][0];
			}
			sort(k,k+ad);
			int l=0;
			while(d!=0){
				man=man-k[l];
				l++;
				d--;
			}cout<<man;
		}if(bd>(zhun[i]/2)){
			int d=bd-zhun[i]/2;
			int k[bd];
			int man=0;
			for(int j=0;j<zhun[i];j++){
				if(pai[0][j][1]==1){
					k[j]=pai[0][j][0]-pai[1][j][0];
				}
				man=man+pai[0][j][0];
			}
			sort(k,k+bd);
			int l=0;
			while(d!=0){
				man=man-k[l];
				l++;
				d--;
			}cout<<man;
		}if(cd>(zhun[i]/2)){
			int d=cd-zhun[i]/2;
			int k[cd];
			int man=0;
			for(int j=0;j<zhun[i];j++){
				if(pai[0][j][1]==2){
					k[j]=pai[0][j][0]-pai[1][j][0];
				}
				man=man+pai[0][j][0];
			}
			sort(k,k+cd);
			int l=0;
			while(d!=0){
				man=man-k[l];
				l++;
				d--;
			}cout<<man;
		}if(ad<=(zhun[i]/2)&&bd<=(zhun[i]/2)&&cd<=(zhun[i]/2)){
			int man=0;
			for(int j=0;j<zhun[i];j++){
				man=man+pai[0][j][0];
			}
			cout<<man;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
