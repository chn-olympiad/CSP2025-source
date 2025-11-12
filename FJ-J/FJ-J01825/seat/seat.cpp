#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=20;

struct student{
	int id;
	int score;
} s[N*N];

int n,m,num[N][N],pos[N*N];

bool cmp(student a,student b){
	return a.score>b.score;
}

// 奇数列递增，偶数列递减 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].score;
		s[i].id=i;
	}
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		pos[s[i].id]=i;
	}
	int now=1,x=1,y=1;
	while(now<=n*m){
		num[x][y]=now;
		if(now==pos[1]){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}else{
			if(x==1) y++;
			else x--;
		}
		now++;
	}
	return 0;
}
