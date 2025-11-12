#include <bits/stdc++.h>
using namespace std;

int N[100005][3];
int N1[100005],N2[100005];
int cnt,n,lim,sum;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		cnt = 0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>N[i][0]>>N[i][1]>>N[i][2];
			N1[i] = N[i][0];
			N2[i] = N[i][1];
			sum += max(N[i][0],max(N[i][1],N[i][2]));
		}
		if(n==2){
			int max1 = 0,max2 = 0,xb1,xb2,s1=0,s2=0;
			for(int j=0;j<=2;j++){
				if(N[1][j]>max1){
					max1 = N[1][j];
					xb1 = j;
				}
				if(N[2][j]>max2){
					max2 = N[2][j];
					xb2 = j;
				}
			}
			if(xb1!=xb2) cout<<max1+max2;
			else{
				for(int j=0;j<=2;j++){
					if(N[1][j]>s1&&j!=xb1){
						s1 = N[1][j];
					}
					if(N[2][j]>s2&&j!=xb2){
						s2 = N[2][j];
					}
				}
				if(max1+s2>max2+s1)cout<<max1+s2;
				else cout<<max2+s1;
			}
		}
		else if(N[1][1]==0){
			sort(N1+1,N1+n+1);
			for(int i=n;i>n/2;i--){
				cnt+=N1[i];
			}
			cout<<cnt;
		}
		else cout<<sum;
	}
	return 0;
}

