#include<bits/stdc++.h> 
using namespace std;

const int N=1e5+5;
int T,n,x=0,y=0,z=0,num=0,m;
int A[N][4];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q3;
priority_queue<pair<int,int>>q;

void Clear(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
	while(!q.empty()) q.pop();
}



int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		Clear();
		num=0;
		memset(A,0,sizeof(A));
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>A[i][1]>>A[i][2]>>A[i][3];
		}
		int r[4];
		for(int i=1;i<=n;i++){
			r[1]=A[i][1];r[2]=A[i][2];r[3]=A[i][3];
			if(r[1]==max(r[1],max(r[2],r[3])) && q1.size()<m) q1.push({r[1]-max(r[2],r[3]),i});
			else if(r[2]==max(r[1],max(r[2],r[3])) && q2.size()<m) q2.push({r[2]-max(r[3],r[1]),i});
			else if(r[3]==max(r[3],max(r[2],r[1])) && q3.size()<m) q3.push({r[3]-max(r[2],r[1]),i});
			else{
				q.push({r[1],1});q.push({r[2],2});q.push({r[3],3});
				pair<int,int>p=q.top();int t;
				if(p.second==1) {
					if(q1.top().first<p.first-max(r[2],r[3])) {t=q1.top().second;q1.pop();q1.push({r[1]-max(r[2],r[3]),i});}
					else t=i;
				}
				else if(p.second==2) {
					if(q2.top().first<p.first-max(r[1],r[3])) {t=q2.top().second;q2.pop();q2.push({r[2]-max(r[1],r[3]),i});}
					else t=i;
				}
				else if(p.second==3) {
					if(q3.top().first<p.first-max(r[2],r[1])) {t=q3.top().second;q3.pop();q3.push({r[3]-max(r[2],r[1]),i});}
					else t=i;
				}
				
				q.pop();q.pop();q.pop();
				q.push({A[t][1],1});
				q.push({A[t][3],3});
				q.push({A[t][2],2});
				q.pop();
				p=q.top();
				if(p.second==1) q1.push({A[t][1]-max(A[t][2],A[t][3]),t});
				if(p.second==2) q2.push({A[t][2]-max(A[t][1],A[t][3]),t});
				if(p.second==3) q3.push({A[t][3]-max(A[t][2],A[t][1]),t});
				q.pop();q.pop();
			}
		}
		while(!q1.empty()) {
			num+=A[q1.top().second][1];
			q1.pop();
		}while(!q2.empty()) {
			//num+=q2.top().first;
			num+=A[q2.top().second][2];
			q2.pop();
		}while(!q3.empty()) {
			//num+=q3.top().first;
			num+=A[q3.top().second][3];
			q3.pop();
		}
		cout<<num<<endl;
	}
	
	
	
	return 0;
}


