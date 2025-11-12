#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int seat[n*m];
	int nowscore=0;
	for(int i = 0;i<n*m;i++){
	cin >> seat[i];	
	}
	nowscore=seat[0];
	sort(seat,seat+n*m-1);
	int nowh=0;
	int nowl=0;
	for(int i =0;i<n*m;i++){
		if(seat[i]==nowscore){
			nowl=i/n+1;
			nowh=i%n+1;
			}
		} 
	cout << nowl << ' ' <<nowh;
	return 0;
	} 
