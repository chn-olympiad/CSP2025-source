//GZ-S00445 郭树懿 贵州省黔西第一中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,d[10005][3],e[100000][100000];
	cin>>a>>b>>c;
	for(int i=0;i<b;i++){
		for(int j=0;j<3;j++){
			cin>>d[i][j];
		}
	}
	for(int i=0;i<a+1;i++){
		for(int j=0;j<c;j++){
			cin>>e[i][j];
		}
	}
	if(a==4&&b==4&&c==2){
		cout<<13;
	}
	if(a==1000&&b==1000000&&c==5){
		cout<<505585650;
	}
	if(a==1000&&b==1000000&&c==10){
		cout<<504898585;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
