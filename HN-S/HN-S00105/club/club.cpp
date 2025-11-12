#include<bits/stdc++.h>
#define X ans+=likes[i][0];memA++;
#define Y ans+=likes[i][1];memB++;
#define Z ans+=likes[i][2];memC++;
using namespace std;
const int mn=1e5+5;
long long ans=0;
int t,n,likes[mn][3],A[mn],B[mn],C[mn];
int memA,memB,memC;

struct club{
	int id,scr;
};
club a[mn],b[mn],c[mn];

bool cmpA(club x,club y){
	if(x.scr>y.scr){
		swap(A[x.id],A[y.id]);
		return true;
	}
	return false;
}

bool cmpB(club x,club y){
	if(x.scr>y.scr){
		swap(B[x.id],B[y.id]);
		return true;
	}
	return false;
}

bool cmpC(club x,club y){
	if(x.scr>y.scr){
		swap(C[x.id],C[y.id]);
		return true;
	}
	return false; 
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memA=0,memB=0,memC=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>likes[i][0]>>likes[i][1]>>likes[i][2];
			A[i]=i,B[i]=i,C[i]=i;
			a[i].id=i,b[i].id=i,c[i].id=i;
			a[i].scr=likes[i][0],b[i].scr=likes[i][1],c[i].scr=likes[i][2];
		}
		sort(a,a+n,cmpA);sort(b,b+n,cmpB);sort(c,c+n,cmpC);
		for(int i=0;i<n;i++){
			if(likes[i][0]>likes[i][1]){
				if(likes[i][1]>likes[i][2]){
					if(memA<n/2){
						X
					}
					else if(memB<n/2){
						Y
					}
					else Z
				}
				else{
					if(likes[i][0]>likes[i][2]){
						if(memA<n/2){
							X
						}
						else if(memC<n/2){
							Y
						}
						else Z
					}
					else{
						if(memC<n/2){
							Z
						}
						else if(memA<n/2){
							X
						}
						else Y
					}
				}
			}
			else{
				if(likes[i][0]>likes[i][2]){
					if(memB<n/2){
						Y
					}
					else if(memA<n/2){
						X
					}
					else Z
				}
				else{
					if(likes[i][1]>likes[i][2]){
						//bca
						if(memB<n/2){
							Y
						}
						else if(memC<n/2){
							Z
						}
						else X
					}
					else{
						//cba
						if(memC<n/2){
							Z
						}
						else if(memB<n/2){
							Y
						}
						else X
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
