#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[100005][3];
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
	return a.first.first>b.first.first;
}
bool cmp2(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
	return a.first.first-a.first.second>b.first.first-b.first.second;
}
void dfs(int k,int sum,int nowpeo[]){
	if(k==n){
		ans=max(sum,ans);
		return;
	}
	for(int i=0;i<3;i++){
		if(nowpeo[i]+1<=n/2){
			nowpeo[i]++;
			dfs(k+1,sum+a[k][i],nowpeo);
			nowpeo[i]--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(n>35){
			pair<pair<int,int>,int>a[100005];
			for(int i=0;i<n;i++){
				cin>>a[i].first.first>>a[i].first.second>>a[i].second;
			}
			if(a[0].second==0&&a[0].first.second==0){
				sort(a,a+n,cmp);
				for(int i=0;i<n/2;i++){
					ans+=a[i].first.first;
				}
				cout<<ans<<'\n';
			}
			else{
				sort(a,a+n,cmp2);
				for(int i=0;i<n/2;i++){
					ans+=a[i].first.first;
				}
				for(int i=n/2;i<n;i++){
					ans+=a[i].first.second;
				}
				cout<<ans<<'\n';
			}
			
			
		}
		else{
			for(int i=0;i<n;i++){
				cin>>a[i][0]>>a[i][1]>>a[i][2];
			}
		
			int nowpeo[3]={0};
			dfs(0,0,nowpeo);
			cout<<ans<<'\n';
	
		}
	
	}
	/*
	rp++rp++rp++
	This is the continuation of The text in the program of xor in the morning
	I am a girl
	Csp-j is easy
	I can get 300 pts
	But csp-s is too difficult for me
	I'm crying
	I only can get less than 100 pts
	I can't go to The No.1 Middle school by this way
	I will go out of oi in 50 minutes
	I like oi
	I don't want to it
	The student beside me is making program of T4
	He is too nb
	I'm fw
	The teacher teach me so slowly that I can't solve questions by DP
	I just can use tree
	I can't solve any question
	I just can use baoli to solve them
	rp++rp++rp++rp++rp++rp++
	Although rp++ is useless
	rp++rp++rp++rp++rp++
	I can't solve yellow questions ontest
	I just can solve orange ones
	Ones is a stupid word
	I like ccf
	I like csp-s
	tarjan
	LCA
	DAG
	KMP
	DP
	DFS
	BFS
	GCD
	LCM
	SPFA
	Hash
	I want to ak csp
	but I can't
	rp++rp++rp++rp++rp++
	Luogu is useful
	I have already solved 7 green questions
	but it isn't enough
	I have learnt oi for two years
	but I am weaker than my greadmate who has learnt for half a year
	My middle school is fw
	I have 30 minutes now
	rp++rp++rp++rp++rp++rp++rp++rp++
	3Fe+2O2====Fe3O4
	I like to play chess and oi
	I want to ak csp noip noi ioi and The Lanqiaocup
	Tell the truth
	noip is easier than csp-s
	I like csp and noip
	rp++rp++rp++rp++rp++
	I don't want to use windows10
	I want to use windows7
	The computer in frent of me is windous7
	I wonder if I can play cards by computer now
	The file is 2.88kb now
	Unless it is more than 100kb
	it don't have any problem
	Csp-s may be easier if it have some untroditional questions
	but it's impossible
	As long as I don't have 0pts
	it's good for me
	rp++rp++rp++rp++rp++rp++rp++rp++
	dev-c++ is yyds
	I have 15 minutes now
	I will go to Chengdu the capital of sf by train next summer holiday
	It will takes me 24 hours
	I love oi and sf very much
	Today is Nov.1st
	the November sfw will get to Shijiazhuang
	Is there a sf about oi
	There was one in the past
	rp++rp++rp++
	I have 10 minutes now
	I don't want to go out of oi
	but I should do it in 10 minutes
	ios::sync_wis_stdio(0) is great
	Don't forget open long long
	Don't forget freopen
	Don't need to write fclose
	it's bad
	inline is useless
	Linux is bad
	I have 5 minutes now
	rp++rp++rp++
	luogu p10000 is difficult
	I have only did about 700 questions
	I have seen a person did 48 questions one day and the hardest is blue
	I will go out
	Test end
	rp++rp++rp++
	*/
	return 0;
}
