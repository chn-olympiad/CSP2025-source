#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=15,maxm=15;
int n,m;
int seats[maxn*maxm];
int ansxy,ansx,ansy;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int N=n*m;
	for(int i=1;i<=N;++i)cin>>seats[i];
	
	int R=seats[1];
	sort(seats+1,seats+1+N);
	for(int i=1;i<=N;++i)
	if(seats[i]==R){
		ansxy=i;
		break;
	}
	
	ansxy=N-ansxy+1;
	ansx=(ansxy-1)/n+1;
	ansy=( ansx&1 ? (ansxy-1)%n+1 : m-((ansxy-1)%n+1)+1);
	cout<<ansx<<" "<<ansy;
	 
	return 0;
}
/*
2 2
99 100 97 98
*/