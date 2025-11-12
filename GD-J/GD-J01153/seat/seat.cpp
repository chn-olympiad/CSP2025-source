#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a;
int w[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	//读入桶排 
	for(int i=1;i<=n*m;i++){
		cin>>a;
		w[a]++;
		if(i==1)a1=a;
	}
	//统计名次 
	int mc=0,q=100;
	while(q!=a1){
		if(w[q]!=0)mc++;
		q--;
	}
	//寻找位置
	int x=1,y=1;//x为行n，y为列m
	while(mc--){
		if(x==n){
			x=0;
			y++;
		}
		x++;
	} 
	//输出
	cout<<y<<" "<<x; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

