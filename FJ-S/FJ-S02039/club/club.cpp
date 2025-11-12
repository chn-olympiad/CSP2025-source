#include <iostream>
#define MAXX 100005
using namespace std;

int T,n,ans;
int s[MAXX][5];
bool check(int i,int j,int k,int l);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			s[i][4]=max(s[i][1],max(s[i][2],s[i][3]));
		}
		if(n==2){
			int maxx=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxx=max(maxx,s[1][i]+s[2][j]);
					}
				}
			}
			cout<<maxx;
		}else if(n==4){
			int maxx=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							if(check(i,j,k,l)){
								maxx=max(maxx,s[1][i]+s[2][j]+s[3][k]+s[4][l]);
							}
						}
					}
				}
			}
			cout<<maxx;
		}
		if(T!=0) cout<<endl;
	}
	return 0;
}

bool check(int i,int j,int k,int l){
	if(i==j&&j==k&&k==l) return false;
	if(i==j&&j==k) return false;
	if(i==k&&k==l) return false;
	if(i==j&&j==l) return false;
	if(j==k&&k==l) return false;
	return true;
}
