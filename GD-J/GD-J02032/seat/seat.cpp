#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int RoW = 0,LinE = 0;
	cin >> RoW >> LinE;
	vector<vector<int>> SeaT(LinE,vector<int>(RoW,0));
	vector<int> AlL(RoW*LinE,0);
	int SelF = 0;
	int PaiWei[2] = {0,0};
	
	for (int i = 0;i < RoW*LinE;i++){
		int ScorE = 0;
		cin >> ScorE;
		AlL[i] = ScorE;
		if (i == 0){
			SelF = ScorE;
		}
	}
	
	sort(AlL.begin(),AlL.end(),greater<int>());
	
	
	for(int i = 0;i < LinE;i++){
		int NoW = 0;
		for(int j = 0;j < RoW;j++){
			if(i%2 != 1){
				NoW = i*RoW + j;
			}else{
				NoW = i*RoW + RoW - j - 1; 
			}
			if(AlL[NoW] == SelF){
				PaiWei[0] = i+1;
				PaiWei[1] = j+1; 
			}
		}  
	}
	
	cout<<PaiWei[0]<<" "<<PaiWei[1];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
