#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct MemberInfo{
	int q1,q2,q3;
	int best,secn;
	int diff;
	const bool operator<(const MemberInfo rhs) const {
		return this->diff>rhs.diff;
	}
	void calc(){
		if(q1==q2) {
			if(q1>=q3) best=1,secn=2,diff=0;
			else best=3,secn=1,diff=q3-q1;
		}
		if(q1>q2){
			if(q2>=q3) best=1,secn=2,diff=q1-q2;
			else if(q1>=q3) best=1,secn=3,diff=q1-q3;
			else best=3,secn=1,diff=q3-q1;
		}
		if(q1<q2){
			if(q1>=q3) best=2,secn=1,diff=q2-q1;
			else if(q2>=q3) best=2,secn=3,diff=q2-q3;
			else best=3,secn=2,diff=q3-q2;
		}
		return;
	}
};

MemberInfo dt[100005];
priority_queue<MemberInfo> pq[4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			//cout<<"Requesting "<<i<<"th data group"<<endl;
			cin>>dt[i].q1>>dt[i].q2>>dt[i].q3;
			dt[i].calc();
			//cout<<"Done."<<dt[i].q1<<" "<<dt[i].q2<<" "<<dt[i].q3<<" "<<dt[i].best<<" "<<dt[i].secn<<" "<<dt[i].diff<<endl;
		}
		for(int i=1;i<=n;i++){
			//cout<<"Processing data group "<<i<<endl;
			pq[dt[i].best].push(dt[i]);
			if(pq[dt[i].best].size()>n/2) {
				auto h=pq[dt[i].best].top();
				//cout<<"data h have been moved! ("<<h.secn<<","<<h.diff<<")"<<endl;
				pq[dt[i].best].pop();
				pq[h.secn].push(h);
			}
			//cout<<"Done!"<<endl;
		}
		int res=0;
		for(int i=1;i<=3;i++){
			//cout<<"Anatyising queue "<<i<<endl;
			while(!pq[i].empty()) {
			//	cout<<"Get an Info from queue"<<endl;
				if(i==1) res+=pq[i].top().q1;
				if(i==2) res+=pq[i].top().q2;
				if(i==3) res+=pq[i].top().q3;
				pq[i].pop();
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
