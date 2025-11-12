#include<bits/stdc++.h>
using namespace std;
struct dp{
	int s;
	bool is_r;
};
void solove(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
vector<dp> d;
bool cmp(dp a,dp b){
	return a.s>b.s;
}
int main(){
	solove();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		int a;
		cin>>a;
		if(i==1){
			d.push_back({a,1});
			continue;
		}
		d.push_back({a,0});
	}
	sort(d.begin(),d.end(),cmp);
	int x=1,y=1;
	int tg=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<x<<","<<y<<" ";
			if(d[tg].is_r==1){
				cout<<x<<" "<<y;
				return 0;
			}
			tg++;
			if(j==m)	continue;
			if(i%2)	y++;
			else	y--;
			
		}
		x++;
//		cout<<endl;
	}
	return 0;
}