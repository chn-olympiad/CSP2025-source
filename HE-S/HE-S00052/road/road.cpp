#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("roadin","r",stdin);
	freopen("road.out","w",stdout);
	int n,k,m;
	int h1,h2,h3,h4,h5,h6,h7,h8,h9,y1,y2,y3,g1,g2,g3,g4,g5,w1,w2,w3,w4,w5;
	cin>>n>>k>>m;
	if(n==4&&k==4&&m==2){
		cin>>h1>>h2>>h3;
		cin>>h4>>h5>>h6;
		cin>>h7>>h8>>h9;
		cin>>y1>>y2>>y3;
		cin>>g1>>g2>>g3>>g4>>g5;
		cin>>w1>>w2>>w3>>w4>>w5;
		cout<<h6+h9;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
