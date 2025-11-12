#include<bits/stdc++.h>
using namespace std;
int main(){
//#Shang4Shan3Ruo6Shui4
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n=0,m=0,a[20][20],i=0,j=0,b[5000],x,y,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
	}
	j=b[1];
	for(int i=1;i<=n*m;i++){
		for(int z=1;z<=n*m-i;z++){
			if(b[z]<b[z+1]){
				int t=b[z];
				b[z]=b[z+1];
				b[z+1]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(j==b[i]){
			c=i;
		}
	}
	x=c/n;
	if(c%n!=0){
		x++;
	}
	y=c%n;
	if(y==0){
		y=m;
	}
	if(x%2==0){
		y=m-y+1;
		cout<<x<<" "<<y;
	}
	else{
		cout<<x<<" "<<y;
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
} 
