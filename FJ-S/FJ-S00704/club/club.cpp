#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	const int MAXN=1e5;
	int q,temp1,temp2,temp3;
	cin>>q;
	
	vector<vector<int>>ques(100010);
	
	int change[100010][5];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq3;
	for(int p=0;p<q;++p){
		int n;
		int tot=0;
		cin>>n;

		while(!pq1.empty()){
			pq1.pop();
		}
		while(!pq2.empty()){
			pq2.pop();
		}
		while(!pq3.empty()){
			pq3.pop();
		}
		for(int i=0;i<n;++i){
			cin>>temp1>>temp2>>temp3;
			int r=max(temp1,temp2);
			int maxn=max(r,temp3);
			ques[i].push_back(temp1);
			ques[i].push_back(temp2);
			ques[i].push_back(temp3);
			//cout<<ques[i][0]<<' '<<ques[i][1]<<' '<<ques[i][2]<<endl;
			//use priority_queue pop mincost point

			if(maxn==temp1){
				change[i][0]=0;
				change[i][1]=maxn-temp2;//the cost of changing
				change[i][2]=maxn-temp3;
				pq1.push({min(change[i][1],change[i][2]),i});
				tot+=temp1;
				if(pq1.size()>n/2){
					pair<int,int> mpoint=pq1.top();
					pq1.pop();
					int point=mpoint.second;
					tot-=mpoint.first;
					//cout<<ques[point][1]<<' '<<ques[point][2]<<endl;
					if(ques[point][1]>ques[point][2]){
						pq2.push(make_pair((ques[point][1]-ques[point][2]),point));//only from 2 to 3
						
					}
					else{
						pq3.push(make_pair((ques[point][2]-ques[point][1]),point));
					}
				}
			}
			else if(maxn==temp2){
				change[i][0]=maxn-temp1;
				change[i][1]=0;//the cost of changing
				change[i][2]=maxn-temp3;
				
				pq2.push({min(change[i][0],change[i][2]),i});
				tot+=temp2;
				if(pq2.size()>n/2){
					pair<int,int> mpoint=pq2.top();
					pq2.pop();
					int point=mpoint.second;
					tot-=mpoint.first;
					if(ques[point][0]>ques[point][2]){
						pq1.push(make_pair((ques[point][0]-ques[point][2]),point));//only from 0 to 3
					}
					else{
						pq3.push(make_pair((ques[point][2]-ques[point][0]),point));
					}
				}
			}
			else if(maxn==temp3){
				change[i][0]=maxn-temp1;
				change[i][1]=maxn-temp2;//the cost of changing
				change[i][2]=0;
			
				pq3.push({min(change[i][0],change[i][1]),i});
				tot+=temp3;
				if(pq3.size()>n/2){
					pair<int,int> mpoint=pq3.top();
					pq3.pop();
					int point=mpoint.second;
					tot-=mpoint.first;
					if(ques[point][0]>ques[point][1]){
						pq1.push(make_pair((ques[point][0]-ques[point][1]),point));//only from 0 to 3
					}
					else{
						pq2.push(make_pair((ques[point][1]-ques[point][0]),point));
					}
				}
			}
			
		}
		cout<<tot<<endl;
	}
	
	return 0;
		
}
