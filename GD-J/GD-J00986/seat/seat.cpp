#include<bits/stdc++.h>
using namespace std;
int n,m,temp,R_sc;
vector<int> score;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++){
		cin>>temp;
		score.push_back(temp);
	}
	R_sc=score[0];
	sort(score.begin(),score.end(),cmp);
	int mk=(find(score.begin(),score.end(),R_sc)-score.begin());
	int line=(mk/n)+1;
	cout<<line<<' ';
	if(line%2==1){
		cout<<(mk%n+1);
	}
	else{
		cout<<n-(mk%n);
	}
	fclose(stdin);
} 
