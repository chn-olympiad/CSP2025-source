#include <bits/stdc++.h>
using namespace std;
struct member{
	int a,b,c;
}lis[100020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n,a=0,b=0,c=0; long long r=0;cin >> n;
		priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qa,qb,qc;
		for(int i = 1;i <= n;i++){
			cin >> lis[i].a >> lis[i].b >> lis[i].c; 
			int tmp=max(lis[i].a,max(lis[i].b,lis[i].c)); r+=tmp;
			if(tmp==lis[i].a){qa.push({min(tmp-lis[i].b,tmp-lis[i].c),i});a++;}
			else if(tmp==lis[i].b){qb.push({min(tmp-lis[i].a,tmp-lis[i].c),i});b++;}
			else{qc.push({min(tmp-lis[i].b,tmp-lis[i].a),i});c++;}
			lis[i].a=tmp-lis[i].a;lis[i].b=tmp-lis[i].b;lis[i].c=tmp-lis[i].c;
			if(a>n/2){
				int ind=qa.top().second; qa.pop(); a--;
				if(lis[ind].b<lis[ind].c){
					r-=lis[ind].b; int t1=lis[ind].b;
					lis[ind].a-=t1; lis[ind].b=0; lis[ind].c-=t1;
					b++; qb.push({min(lis[ind].a,lis[ind].c),ind});
				}
				else{
					r-=lis[ind].c; int t1=lis[ind].c;
					lis[ind].a-=t1; lis[ind].b-=t1; lis[ind].c-=t1;
					c++; qc.push({min(lis[ind].a,lis[ind].b),ind});
				}
			}
			if(b>n/2){
				int ind=qb.top().second; qb.pop(); b--;
				if(lis[ind].a<lis[ind].c){
					r-=lis[ind].a; int t1=lis[ind].a;
					lis[ind].a-=t1; lis[ind].b-=t1; lis[ind].c-=t1;
					a++; qa.push({min(lis[ind].c,lis[ind].b),ind});
				}
				else{
					r-=lis[ind].c; int t1=lis[ind].c;
					lis[ind].a-=t1; lis[ind].b-=t1; lis[ind].c-=t1;
					c++; qc.push({min(lis[ind].a,lis[ind].b),ind});
				}
			}
			if(c>n/2){
				int ind=qc.top().second; qc.pop(); c--;
				if(lis[ind].a<lis[ind].b){
					r-=lis[ind].a; int t1=lis[ind].a;
					lis[ind].a-=t1; lis[ind].b-=t1; lis[ind].c-=t1;
					a++; qa.push({min(lis[ind].c,lis[ind].b),ind});
				}
				else{
					r-=lis[ind].b; int t1=lis[ind].b;
					lis[ind].a-=t1; lis[ind].b-=t1; lis[ind].c-=t1;
					b++; qb.push({min(lis[ind].a,lis[ind].c),ind});
				}
			}
		}cout << r << endl;
	}
	return 0;
}
