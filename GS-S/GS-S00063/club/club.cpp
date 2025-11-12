#include<bits/stdc++.h>
using namespace std;
int fen(){
	int n;
	cin>>n;
	int my[n][3],zd=0,gr[n],bm[3]{0,0,0};
	for(int j=0;j<n;j++){
		gr[j]=0;
		cin>>my[j][0]>>my[j][1]>>my[j][2];
		if(my[j][0]>gr[j]){
			gr[j]=my[j][0];
			bm[0]++;
		} 
		if(my[j][1]>gr[j]){
			gr[j]=my[j][1];
			bm[1]++;
		}
		if(my[j][2]>gr[j]){
			gr[j]=my[j][2];
			bm[2]++;
		}
		int h[n+1];
		h[0]=0;
		int g;
		for(g=0;g<n;g++){
			int dx=0;
			while(gr[g]<h[dx]){
				dx++;
			}
			int k=0;
			for(k=0;k<n-dx;k++){
				h[n-k]=h[n-k-1];
			}
			h[dx]=gr[g];
		}
		if(bm[0]>n/2){
			for(int k=0;k<bm[0]-n/2;k++){
				int g=0;
				while(gr[g]!=h[j-k]){
					g++;
				}
				gr[j]=gr[j]+my[g][1]-gr[g];
			}
		}
		if(bm[1]>n/2){
			for(int k=0;k<bm[1]-n/2;k++){
				int g=0;
				while(gr[g]!=h[j-k]){
				g++;
				
				}
				gr[j]=gr[j]+my[g][2]-gr[g];
			}
		}
		if(bm[2]>n/2){
			for(int k=0;k<bm[2]-n/2;k++){
				int g=0;
				while(gr[g]!=h[j-k]){
				g++;
				
				}
				gr[j]=gr[j]+my[g][0]-gr[g];
			}
		}
		zd=zd+gr[j];
	}
	
	return zd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int jg[t];
	for(int i=0;i<t;i++){
		jg[i]=fen();
	}
	for(int i=0;i<t;i++){
		cout<<jg[i]<<"\n";
		
	}
	
	return 0;
}
