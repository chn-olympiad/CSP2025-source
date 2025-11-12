#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	
	int n=0,m=0;
	std::cin>>n>>m;
	int s;
	int sc[101]={0};
	cin>>s;
	for(int i=0;i<m*n-1;i++)
		cin>>sc[i];
	sort(sc,sc+m*n);
	for(int i=0;i<m*n;i++){
		if(sc[i]<=s&&sc[i+1]>=s){
			s=i;
			break;
		}
	}
	std::cout<<s%n+1<<" "<<s/n+1;
	return 0;
} 