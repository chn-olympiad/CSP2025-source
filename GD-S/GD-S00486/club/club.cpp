#include<bits/stdc++.h>
using namespace std;
int l[100005][3],A[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--){
		int x,finas=-1,flg=0;
		cin>>x;
		for(int i=0;i<x;i++){
			cin>>l[i][0]>>l[i][1]>>l[i][2];
			A[i]=l[i][0];
			if(l[i][1]!=0 or l[i][2]!=0)flg=1;
		}
		if(flg==0){//t12
			sort(A,A+x);finas=0;
			for(int i=x-1;i>=x/2;i--)finas+=A[i];
			cout<<finas<<endl;
		}else if(x==2){//t1
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i==j)continue;
					finas=max(finas,l[0][i]+l[1][j]);
				}
			}
			cout<<finas<<endl;
		}else if(x==4){//t2
			for(int m=0;m<3;m++){
				for(int n=0;n<3;n++){
					for(int o=0;o<3;o++){
						for(int p=0;p<3;p++){
							if((m==n and n==o)or(m==n and n==p)or(p==n and n==o)or(m==p and p==o))continue;
							finas=max(finas,l[0][m]+l[1][n]+l[2][o]+l[3][p]);
						}
					}
				}
			}
			cout<<finas<<endl;
		}else{
			finas=0;
			int res[5]={0,0,0};
			for(int i=0;i<x;i++){
				int X,Y,Z;
				X=max(l[i][0],max(l[i][1],l[i][2]));
				Z=min(l[i][0],min(l[i][1],l[i][2]));
				Y=l[i][0]+l[i][1]+l[i][2]-X-Z;
				if(X==l[i][0]){
					if(res[0]<x/2){
						finas+=X;
						res[0]++;
					}else if(Y==l[i][1]){
						if(res[1]<x/2){
							finas+=Y;
							res[1]++;
						}else{
							finas+=Z;
							res[2]++;
						}
					}else{
						if(res[2]<x/2){
							finas+=Y;
							res[2]++;
						}else{
							finas+=Z;
							res[1]++;
						}
					}
				}else if(X==l[i][1]){
					if(res[1]<x/2){
						finas+=X;
						res[1]++;
					}else if(Y==l[i][0]){
						if(res[0]<x/2){
							finas+=Y;
							res[0]++;
						}else{
							finas+=Z;
							res[2]++;
						}
					}else{
						if(res[2]<x/2){
							finas+=Y;
							res[2]++;
						}else{
							finas+=Z;
							res[0]++;
						}
					}
				}else{
					if(res[2]<x/2){
						finas+=X;
						res[2]++;
					}else if(Y==l[i][0]){
						if(res[0]<x/2){
							finas+=Y;
							res[0]++;
						}else{
							finas+=Z;
							res[1]++;
						}
					}else{
						if(res[1]<x/2){
							finas+=Y;
							res[1]++;
						}else{
							finas+=Z;
							res[0]++;
						}
					}
				}
			}cout<<finas<<endl;
		}
	}
	return 0;
}
