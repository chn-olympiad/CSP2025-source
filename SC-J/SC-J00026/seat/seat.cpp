#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;
	int k[105];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>k[i];
		if(i!=1&&k[i]>k[1])p++;
	}
	int tx=1,ty=1,flag=0;
	for(int i=1;i<=p;i++){
		if(i%n==0){
			tx++;
			if(flag==0)flag=1;
			else flag=0;
		}
		else if(flag==0)ty++;
		else if(flag==1)ty--;
	}
	cout<<tx<<" "<<ty;
	return 0;
}