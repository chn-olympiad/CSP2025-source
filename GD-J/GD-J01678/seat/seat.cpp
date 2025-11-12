#include <bits/stdc++.h>
using namespace std;
int n,m,a1; 
priority_queue<int,vector<int>,less<int> > que;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=1;
	for(int i=1;i<=n*m;i++){
		int temp;
		cin>>temp;
		if(i==1){
			a1=temp;
		}	
		que.push(temp);
	}
	int c,r;
	for(int i=1;i<=m;i++){
		int way=i%2;
		
		if(way==1){
			for(int j=1;j<=n;j++){
				int NowGrade=que.top();
				que.pop();
				if(NowGrade==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				int NowGrade=que.top();
				que.pop();
				if(NowGrade==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
