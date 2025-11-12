#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int num[N][3];
int cnt[N];


//int l[4][3]={{4,7,0},{3,9,0},{5,12,0},{3,9,0}};
//
//bool cmp(int a,int b){
//	return (l[a][0]*l[b][1]>l[b][0]*l[a][1]);
//}

//bool compare(int a,int b){
//	return d[a][step]>d[b][step];
//}

//bool compare1(int a,int b){
//	return (num[a][0]*sum[b]>num[b][0]*sum[a]);
//}
//
//bool compare2(int a,int b){
//	return (num[a][1]*sum[b]>num[b][1]*sum[a]);
//}
//
//bool compare3(int a,int b){
//	return (num[a][2]*sum[b]>num[b][2]*sum[a]);
//}

priority_queue<pair<double,int>> qu1;
priority_queue<pair<double,int>> qu2;
priority_queue<pair<double,int>> qu3;

void init(){
	while(!qu1.empty())qu1.pop();
	while(!qu2.empty())qu2.pop();
	while(!qu3.empty())qu3.pop();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int x,y,z;
		init(); 
		cin>>n;
		for(int i=0;i<n;i++)cnt[i]=0;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			num[i][0]=x;
			num[i][1]=y;
			num[i][2]=z;
			double tmp=(x+y+z);
			qu1.push({x/tmp,i});
			qu2.push({y/tmp,i});
			qu3.push({z/tmp,i});

		}
		int sum=0;
		int m=0;
		
//		while(!qu1.empty()){
//			double t1=qu1.top().first;
//			int t2=qu1.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][0]<<endl;
//
//			qu1.pop();
//		}
//		cout<<endl;
//
//		while(!qu2.empty()){
//			double t1=qu2.top().first;
//			int t2=qu2.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][1]<<endl;
//			qu2.pop();
//		}
//		cout<<endl;
//		m=0;
//		while(!qu3.empty()){
//			double t1=qu3.top().first;
//			int t2=qu3.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][2]<<endl;
//			qu3.pop();
//		}
//		
		
		while(!qu1.empty()&&m<n/2){
			double t1=qu1.top().first;
			int t2=qu1.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][0]<<endl;
			if(cnt[t2]<num[t2][0]){
				sum=sum-cnt[t2]+num[t2][0];
				cnt[t2]=num[t2][0];
//				cout<<".."<<t2<<endl;
			}m++;
			qu1.pop();
		}
//		cout<<endl;
		m=0;
//		cout<<"<1>"<<endl;
		while(!qu2.empty()&&m<n/2){
			double t1=qu2.top().first;
			int t2=qu2.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][1]<<endl;
			if(cnt[t2]<num[t2][1]){
				sum=sum-cnt[t2]+num[t2][1];
				cnt[t2]=num[t2][1];
//				cout<<".."<<t2<<endl;
			}m++;
			qu2.pop();
		}
//		cout<<endl;
		m=0;
//		cout<<"<1>"<<endl;
		while(!qu3.empty()&&m<n/2){
			double t1=qu3.top().first;
			int t2=qu3.top().second;
//			cout<<t2<<"=>"<<t1<<" "<<num[t2][2]<<endl;
			if(cnt[t2]<num[t2][2]){
				sum=sum-cnt[t2]+num[t2][2];
				cnt[t2]=num[t2][2];
//				cout<<".."<<t2<<endl;
			}m++;
			qu3.pop();
		}

		cout<<sum<<endl;
		int cnt1=0,cnt2=0,cnt3=0;
		
	}
	return 0;
} 
/*
1
10
5491 4476 -6362
9805 9130 -15480
9090 -9901 10480 +579
6326 -6516 1985 -190
-9119 2924 6420 
9826 -12689 7592
7293 -16544 12901
11905 18183 -18712 -600
9015 3463 -13025
1792 2433 -17042

4=>0.493907 9119
3=>0.426654 6326
8=>0.353488 9015
0=>0.336273 5491
5=>0.326369 9826

125440



*/


