#include<bits/stdc++.h>

int grade[250]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int peo=m*n;
	for(int i=1;i<=peo;i++)cin>>grade[i];
	int R=grade[1];
	sort(grade+1,grade+peo+1,greater<int>());
	int gR=0;
	for(int i=1;i<=peo;i++){
		if(grade[i]==R){
			gR=i;
			break;
		}
	} 
	int r=0,c=0;
	r=gR/n; 
	if(gR%n!=0)r++;
	c=r*n-gR+1;
	if(r%2==0){
	}else{
		c=n-c+1;
	}
	cout<<r<<" "<<c;
	return 0;
} 
