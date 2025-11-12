#include <bits/stdc++.h> 
using namespace std;	
int a,b,c,d[1000000][3],e[10000000][1000000],qq;
int mian(int f,int ee,int j){
	if(f==j){
		return ee;
	}
	for(int i=0;i<b;i++){
		if(d[i][1]==f){
			f=d[i][0];
			ee=ee+d[i][3];
			return mian(f,ee,j);
		}
		if(d[i][0]==f){
			f=d[i][1];
			ee=ee+d[i][3];
			return mian(f,ee,j);
		}
	}
	for(int i=0;i<c;i++){
		
		return e[i][f]+e[i][j]+e[i][0];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ee,f,j;
	cin>>a>>b>>c;
	qq=0;
	for(int i=0;i<b;i++){
		cin>>d[i][0]>>d[i][1]>>d[i][2];
	}
	for(int i=0;i<c;i++){
		for(long ii=0;ii<c+1;ii++){
			cin>>e[i][ii];
		}
	}
	for(int i=0;i<c;i++){
		for(int ii=0;ii<c;ii++){
			f=i;
			j=ii;
			ee=0;
			qq=max(qq,mian(f,ee,j));
		}
	}
	cout<<qq;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
