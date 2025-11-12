#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
pair<int,int> mp[105];
int x,xpos;

void gen(){//generate seatmap
	int now=1;
	int nowM=1;
	bool dir=true;
	while(now<=n*m){
		if(dir){
			for(int i=1;i<=n;i++){//dir 1:UP(when number is even)
				mp[now]=make_pair(i,nowM);
				now++;
			}
		}
		else{
			for(int i=n;i>=1;i--){//dir 2:DOWN(when number is odd)
				mp[now]=make_pair(i,nowM);
				now++;
			}
		}
		nowM++;
		dir=!dir;//change direction everytime reaches the top or the bottom.
	}
}
bool cmp(int a,int b){//comparing function
	return a>b;
}
int main(){
	//fstream reopen
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//d&u
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//input matrix size
	cin>>n>>m;
	//generate seatmap
	gen();
	//input scores
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x = a[1];//record R's score to find his pos
	sort(a+1,a+m*n+1,cmp);//sort it.
	for(int i=1;i<=n*m;i++){//find it.
		if(a[i] == x){
			xpos = i;
			break;
		}
	}
	//output it.
	cout<<mp[xpos].second<<" "<<mp[xpos].first<<"\n";
	return 0;
}