#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define uint unsigned int
#define str string
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,rf;//行数，列数，小R分数
	pair<int,int> seat;//小R座位号
	cin>>n>>m;
	vector<int> s;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		s.emplace_back(a);
		if(i==1){
			rf=a;
		}
	}
	sort(s.begin(),s.end());
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(s[i*i+j-(i+1)]==rf){
					seat.first=j;
					seat.second=i;
				}
			}
		}else{
			for(int j=n;j>0;j--){
				if(s[i*i+j-(i+1)]==rf){
					seat.first=j;
					seat.second=i;
				}
			}
		}
	}
	cout<<seat.first<<" "<<seat.second;
	return 0;
}