#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>score;
	vector< vector<int> >list(n+1,vector<int>(m+1));
	for(int i=0;i<n*m;i++){
		int s;
		cin>>s;
		score.push_back(s);
	}
	int a=score[0];
	sort(score.begin(),score.end(),greater<int>());
	auto it=find(score.begin(),score.end(),a);
	int dis=distance(it,score.begin());
	int idx=0;
	bool updown=1;
	for(int i=1;idx!=n*m+1;i++){
		if(updown==1){
			for(int j=1;j<=m;j++){
				list[i][j]==idx;
				if(a==score[idx]){
					cout<<i<<' '<<j;
					return 0;
				}
				idx++;
			}
		}
		else{//up
			for(int j=m;j>=1;j--){
				list[i][j]==idx;
				if(a==score[idx]){
					cout<<i<<' '<<j;
					return 0;
				}
				idx++;
			}
		}
		updown=!updown;
	}
}
