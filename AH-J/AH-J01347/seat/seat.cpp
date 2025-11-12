#include<bits/stdc++.h>
using namespace std;
long long num[105][105],num1[105];
long long n,m,cnt=0,cheng,jk=0,ii=1,bb=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//scanf("%.lld",&n,&m);
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			//scanf("%.lld",&num[i][j]);
			cin>>num[i][j];
			num1[cnt]=num[i][j];
			if(i==1 && j==1){
				cheng=num[i][j];
			}
			cnt++;
		}
	}
	sort(num1,num1+cnt);
		while(jk<=n && ii<=m){
			if(ii%2==1){
				jk++;
			}
			if(ii%2==0){
				jk--;
			}
			if(jk==n+1){
				if(bb==n){
					ii++;
					jk--;
					bb=0;
				}
			}
			if(jk==0){
				if(bb==n){
					ii++;
					jk++;
					bb=0;
				}
			}
			num[ii][jk]=num1[cnt-1];
			cnt--;
			bb++;
			if(cheng==num[ii][jk]){
				cout<<ii<<" "<<jk;
				break;
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92

