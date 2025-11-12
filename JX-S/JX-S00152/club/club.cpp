#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int a,b,c[N][3],d=0,e=0,f=0,g=0,h[6]={0},k[N][3],m[N][2],l=0,o;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		for(int j=0;j<b;j++){
			cin>>c[j][0]>>c[j][1]>>c[j][2];
			if(c[j][0]>c[j][1] and c[j][0]>c[j][2]) {e++;d+=c[j][0];k[j][0]=0;k[j][1]=min(c[j][0]-c[j][1],c[j][0]-c[j][2]);k[j][2]=max(c[j][0]-c[j][1],c[j][0]-c[j][2]);}
			else if(c[j][1]>c[j][0] and c[j][1]>c[j][2]){f++;d+=c[j][1];k[j][0]=1;k[j][1]=min(c[j][1]-c[j][0],c[j][1]-c[j][2]);k[j][2]=max(c[j][1]-c[j][0],c[j][1]-c[j][2]);}
			else {g++;d+=c[j][2];k[j][0]=2;k[j][1]=min(c[j][2]-c[j][1],c[j][2]-c[j][0]);k[j][2]=max(c[j][2]-c[j][1],c[j][2]-c[j][0]);}
		}
		if(e<=(b/2) and f<=(b/2) and g<=(b/2)){
			h[i]=d;d=0;e=0;f=0;g=0;l=0;continue;
		}
		if(b>2 and ((c[i][0]==c[i+1][0] and c[i][2]==c[i+1][2]) or (c[i][1]==c[i+1][1] and c[i][2]==c[i+1][2]) or (c[i][0]==c[i+1][0] and c[i][1]==c[i+1][1])) and (c[i][0]==0 or c[i][1]==0 or c[i][2]==0)){
			h[i]=0;
			for(int j=b;j>=(b/2);j--){
				h[i]+=k[j][1];
			}
			d=0;e=0;f=0;g=0;l=0;continue;
		}if(e>(b/2)){
			for(int j=0;j<b;j++){
				if(k[j][0]==0){
					m[l][0]=k[j][1];
					m[l][1]=j;
					l++;
				}
			}
			for(int j=0;j<b-1;j++){
				for(int n=0;n<b-1;n++){
					if(m[n][0]<m[n+1][0]){
						o=m[n][0];m[n][0]=m[n+1][0];m[n+1][0]=o;
						o=m[n][1];m[n][1]=m[n+1][1];m[n+1][1]=o;
					}
				}
			}
			l--;
			while(e>(b/2)){
				d-=m[l][0];
				l-=1;
				e--;
				f++;
				k[m[l][1]][0]=1;
			}
			h[i]=d;d=0;e=0;f=0;g=0;l=0;continue;
		}if(f>(b/2)){
			l=0;
			for(int j=0;j<b;j++){
				if(k[j][0]==0){
					m[l][0]=k[j][1];
					m[l][1]=j;
					l++;
				}
			}
			for(int j=0;j<b-1;j++){
				for(int n=0;n<b-1;n++){
					if(m[n][0]<m[n+1][0]){
						o=m[n][0];m[n][0]=m[n+1][0];m[n+1][0]=o;
						o=m[n][1];m[n][1]=m[n+1][1];m[n+1][1]=o;
					}
				}
			}
			l--;
			while(f>(b/2)){
				d-=m[l][0];
				l-=1;
				f--;
				g++;
				k[m[l][1]][0]=2;
			}
			h[i]=d;d=0;e=0;f=0;g=0;l=0;continue;
		}if(g>(b/2)){
			for(int j=0;j<b;j++){
				if(k[j][0]==0){
					m[l][0]=k[j][1];
					m[l][1]=j;
					l++;
				}
			}
			for(int j=0;j<b-1;j++){
				for(int n=0;n<b-1;n++){
					if(m[n][0]<m[n+1][0]){
						o=m[n][0];m[n][0]=m[n+1][0];m[n+1][0]=o;
						o=m[n][1];m[n][1]=m[n+1][1];m[n+1][1]=o;
					}
				}
			}
			l--;
			while(g>(b/2)){
				d-=m[l][0];
				l-=1;
				g--;
				e++;
				k[m[l][1]][0]=0;
			}
			h[i]=d;
		}
		d=0;e=0;f=0;g=0;l=0;
	}
	for(int i=0;i<a;i++){
		cout<<h[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
