#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int u=a*b;
	int o[u];
	for(int q=0;q<u;q++){
		cin>>o[q];
	}
	int s=o[0];
	sort(o,o+u);
	int p[u];
	for(int w=0;w<u;w++){
		p[w]=o[u-w-1];
	}
	int klh[a][b];
	int lrx=0;
	int j,k;
	for(int e=1;e<=b;e++){
		if(e%2==1){
			for(int r=1;r<=a;r++){
				klh[r][e]=o[lrx];
				lrx++;
				if(o[lrx]==s){
					j=r;
					k=e;
					break;
				}
			}
		}else{
			for(int t=a;t>=1;t--){
				klh[t][e]=o[lrx];
				lrx++;
				if(o[lrx]==s){
					j=t;
					k=e;
					break;
				}
			}
		}
	}
	cout<<a-j+1<<" "<<b-k+1;
	return 0;
}
