#include<bits/stdc++.h>
using namespace std;

int n,m,x=1,y=1,cnt;
struct node{
	int id,sc;
}s[105];

bool cmp(node x,node y){
	return x.sc>y.sc;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>s[i].sc;
		s[i].id=i;
	}
	
	sort(s+1,s+t+1,cmp);
	
	while(cnt<=t){
		cnt++;
		if(s[cnt].id==1){
			cout<<x<<" "<<y;
			break;
		}
		if(x%2==1){
			if(y==n) x++;
			else y++;
		}else{
			if(y==1) x++;
			else y--;
		}
	}
	
	return 0;
}
