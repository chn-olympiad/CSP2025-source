#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int score;
	bool r;
}s[105];
bool cmp(node a,node b){
	return a.score > b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i ++){
		cin>>s[i].score;
		if(i == 1){
			s[i].r = 1;
		}else{
			s[i].r = 0;
		}
	}
	sort(s + 1,s + n * m + 1,cmp);
	int ind = 1;
	for(int i = 1;i <= n;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j ++){
				if(s[ind].r == 1){
					cout<<i<<" "<<j;
					return 0;
				}
				ind ++;
			}
		}else{
			for(int j = m;j >= 1;j --){
				if(s[ind].r == 1){
					cout<<i<<" "<<j;
					return 0;
				}
				ind ++;
			}
		}
	}
	return 0;
}
