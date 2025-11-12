#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[3],max_dept,max_s,best;
long long sum;
struct per{
	int s[3];
}; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		vector <per> p(n);
		for(int i=0 ; i<n ; i++)	cin>>p[i].s[0]>>p[i].s[1]>>p[i].s[2];
			
		sort(p.begin(),p.end(), [](const per &a ,const per &b){
			vector <int> sa={a.s[0],a.s[1],a.s[2]};
			vector <int> sb={b.s[0],b.s[1],b.s[2]};
			sort(sa.rbegin(),sa.rend());
			sort(sb.rbegin(),sb.rend());
			return (sa[0]-sa[1]) > (sb[0]-sb[1]);
		});
		
		cnt[3]={0};
		max_dept=n/2;
		sum=0;
		for(auto & per:p){
			best=-1,max_s=-1;
			for(int i=0 ; i<3 ; i++){
				if(cnt[i]<max_dept && per.s[i]>max_s){
					max_s=per.s[i];
					best=i;
				}
			}
			cnt[best]++;
			sum+=max_s;
		}
		cout<<sum<<endl;
	}
	return 0;
}

