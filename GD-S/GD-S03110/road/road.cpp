#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MAXMa=1e5+10 ;
int a;
int s;
int d;
int v;
int w1[100050],w2;
int u;
int lq;
int dis[100050],qwe[100050];
int waya[100050][100050];
vector<int> G[106000];
int asd(int q,int qw){
	queue<int>ew;
	ew.push(q);
	dis[q]=1,qwe[q]=0;
	while(!ew.empty()){
		for (int i=0:i<=waya[q].size();i++){
			if(qwe[]<=qwe[]+waya[][])
				qwe[]<=qwe[]+waya[][]
				if()
		}
	}
}
int main(){
	//freopen("road.in ","r",stdin);
	//freopen("road.out","w",stdout);
		cin>>a>>s>>d;
		for(int i=0;i<s;i++){
			for(int k=0;k<3;k++){
					cin>>u>>v>>w1[s];
					waya[u][v]=w1[s];
				}
			}
		for(int j=0,j<d,j++){
			cin>>lq;
			for(int k=0,k<a,k++){
				cin>>w2;
				waya[100000+j][k]=w2+lq;
			}
		}
		
		return 0;
	}
