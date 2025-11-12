#include <bits/stdc++.h>
using namespace std;
int a,b,c[10][10]={0},d,e[100],f,g,h=0;
bool k[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<100;i++){
		k[i]=false;
	}
	for(int i=0;i<a*b;i++){
		cin>>e[i];
		k[e[i]]=true;
	}
	d=e[0];
	for(int i=100;i>=0;i--){
		if(k[i]==true){
			h++;
			if(i==d)break;	
		}
	}
	for(int i=0;i<b;i++){
		g=i*a+1;
		if(i%2==0){
			for(int j=0;j<a;j++){
				c[j][i]=g;
				g++;
			}
		}
		else{
			for(int j=a-1;j>=0;j--){
				c[j][i]=g;
				g++;
			}
		}
		if(g>h) break;
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<a;i++){
			if(c[i][j]==h){
				cout<<j+1<<" "<<i+1;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
