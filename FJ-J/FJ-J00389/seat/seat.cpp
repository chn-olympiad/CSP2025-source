#include<bits/stdc++.h>
using namespace std;
int n,m;
int sett[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int als=n*m;
	for(int i=1;i<=als;i++){
		cin>>sett[i];
	}
	int ours=sett[1];
	sort(sett+1,sett+1+als);
	int l=1,r=als;
	while(l<=r) swap(sett[l++],sett[r--]);
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			if(sett[i*n+j]==ours){
				if((i+1)%2==0) j=n+1-j;
				cout<<i+1<<' '<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 