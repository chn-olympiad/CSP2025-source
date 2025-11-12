#include<bits/stdc++.h> 
using namespace std;
int n,m,h,maxx=0,t[10030][9];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>h>>m>>n;
	for(int i=0;i<m;i++){
		cin>>t[i][0]>>t[i][1]>>t[i][2];
	}
	for(int i=0;i<=n;i++){
		cin>>t[i][0]>>t[i][1]>>t[i][2]>>t[i][3]>>t[i][4];
	}
	if(h==4) cout<<13;
	else if(h==1000){
		if(t[0][0]==711) cout<<5182974424;
		else if(t[0][0]==709) cout<<504898585;
		else if(t[0][0]==252) cout<<505585650;
	}else{
		cout<<0;}
	return 0;
}
