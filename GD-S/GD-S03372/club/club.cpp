#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+100;
int T,n,a1[N],a2[N],a3[N];
int sum;
vector<int> s1,s2,s3;
bool cmp1(int a,int b){return a1[a]<a1[b];}
bool cmp2(int a,int b){return a2[a]<a2[b];}
bool cmp3(int a,int b){return a3[a]<a3[b];}

void work(int id,vector<int> ts){
	int left = ts.size()-n/2;
	priority_queue<int> p;
	for(int i = 0;i < ts.size();i ++){
		if(id == 1)p.push(max(a2[ts[i]],a3[ts[i]])-a1[ts[i]]);
		if(id == 2)p.push(max(a1[ts[i]],a3[ts[i]])-a2[ts[i]]);
		if(id == 3)p.push(max(a1[ts[i]],a2[ts[i]])-a3[ts[i]]);
	}
	while(left--){
		sum += p.top();
		p.pop();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		s1.clear();
		s2.clear();
		s3.clear();
		sum = 0;
		for(int i = 1;i <= n;i ++){
			cin >> a1[i] >> a2[i] >> a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				s1.push_back(i);
				sum += a1[i];	
			}
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				s2.push_back(i);
				sum += a2[i];
			}
			else if(a3[i]>=a1[i]&&a3[i]>=a2[i]){
				s3.push_back(i);
				sum += a3[i];
			}
		}	
		sort(s1.begin(),s1.end(),cmp1);
		sort(s2.begin(),s2.end(),cmp2);
		sort(s3.begin(),s3.end(),cmp3);
		if(s1.size()>n/2)work(1,s1);
		else if(s2.size()>n/2)work(2,s2);
		else if(s3.size()>n/2)work(3,s3);
		cout << sum << '\n';
	}
	return 0;
} 
