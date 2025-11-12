#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt=0;
	cin>>n>>m;
	vector<vector<int>> seats(n,vector<int>(m));
	vector<int> scores(n*m);
	for(int i=0;i<n*m;i++){
		cin>>scores[i];
	}
	r=scores[0];
	sort(scores.begin(),scores.end());
	reverse(scores.begin(),scores.end());
	for(int i=0;i<m;i++){//column
		if(i%2==0){
			for(int j=0;j<n;j++){//row
				seats[j][i]=scores[cnt];
				cnt++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){//row
				seats[j][i]=scores[cnt];
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++){//row
		for(int j=0;j<m;j++){//column
			if(seats[i][j]==r){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
} 
