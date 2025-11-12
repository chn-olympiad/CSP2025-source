#include<bits/stdc++.h>
using namespace std;
int jieguo[10000000];
int www[3];
int bbb[3];
int rrr[3];
int uuu=0,a=0;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    	int n=0;
    	cin>>n;
    	int w[n][3];
    	int ww[n][3];
    	for(int j=0;j<n;j++){
    		for(int k=0;k<3;k++){
    			cin>>w[j][k];
			}
		}for(int j=0;j<n;j++){
    		for(int k=0;k<3;k++){
    			www[k]=w[j][k];
    			bbb[k]=www[k];
			}if(bbb[0]>bbb[1]){
				a=bbb[0];
				bbb[0]=bbb[1];
				bbb[1]=a;
			}if(bbb[1]>bbb[2]){
				a=bbb[1];
				bbb[2]=bbb[1];
				bbb[1]=a;
			}if(bbb[0]>bbb[1]){
				a=bbb[0];
				bbb[0]=bbb[1];
				bbb[1]=a;
			}for(int q=0;q<3;q++){
				if(www[q]==bbb[2]){
					rrr[q]++;
					break;
				}
			}for(int h=0;h<3;h++){
					ww[j][h]=bbb[h];
				}
			uuu=uuu+bbb[2];
		}
		if(rrr[0]<=n/2&&rrr[1]<=n/2&&rrr[2]<=n/2){
			jieguo[i]=uuu;
			rrr[0]=0;
			rrr[1]=0;
			rrr[2]=0;
			uuu=0;
		}else{
			while(rrr[0]>n/2&&rrr[1]>n/2&&rrr[2]>n/2){
		if(rrr[2]>n/2){
			jieguo[i]=uuu-ww[i][2]+ww[i][1];
			rrr[0]=0;
			rrr[1]=0;
			rrr[2]=0;
			uuu=0;
		}else if(rrr[1]>n/2){
			jieguo[i]=uuu-ww[i][1]+ww[i][0];
			rrr[0]=0;
			rrr[1]=0;
			rrr[2]=0;
			uuu=0;
		}else if(rrr[0]>n/2){
			if(w[i][1]>w[i][2]){
				jieguo[i]=uuu-ww[i][0]+ww[i][1];
			}else{
				jieguo[i]=uuu-ww[i][0]+ww[i][2];
			}
			rrr[0]=0;
			rrr[1]=0;
			rrr[2]=0;
			uuu=0;
		}}}
	}for(int p=0;p<t;p++){
		cout<<jieguo[p]<<endl;
	}
return 0;
}
