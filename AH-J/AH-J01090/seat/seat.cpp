#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cd;
int a[105],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cd=n*m;
	for(int i=1;i<=cd;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+cd+1);
	for(int i=1;i<=cd;i++){
		if(a[i]==c){
			c=cd-i+1;
			break;
		}
	}
	int cnt=0;
	int x=1,y=0;
	while(true){
		cnt++;
		if(x%2==1){
			y++;
			if(y==n+1){
				x++;
				y=n;
			}
		}else{
			y--;
			if(y==0){
				x++;
				y=1;
			}
		}
		if(cnt==c){
			break;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
