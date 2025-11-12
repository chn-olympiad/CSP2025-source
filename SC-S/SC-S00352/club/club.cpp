#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
		int N; cin>>N;
		int M[N][3];
		vector<vector<int>> Ans(3);
		for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++)
			cin >> M[i][j];
		for(int i = 0; i < N; i++) {
			int max=0;
			for (int j = 0; j < 3; j++)
				if(M[i][j]>M[i][max])max=j;
			Ans[max].push_back(i);
		}
		int duole;
		if(Ans[1].size()>N/2)duole=1;
		if(Ans[2].size()>N/2)duole=2;
		if(Ans[3].size()>N/2)duole=3;
		int duode=Ans[duole].size()-N/2;
		int sizeAns=Ans[duole].size();
		for (int i = 0; i < duode; i++) {
			int min=0;
			for (int j = 0; j < sizeAns; j++) {
				
			}
			for (int j = 0; j < sizeAns; j++) if(Ans[duole][j]==min)Ans[duole][j]=-1;
			int max=0,max2=0;
			for (int j=0; j < 3; j++) {
				if(M[min])
			}
		}
	}
}
