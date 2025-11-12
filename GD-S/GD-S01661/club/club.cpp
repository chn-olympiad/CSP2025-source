#include <bits/stdc++.h>
using namespace std;
int num_of_data,n;
int ru[100004][5];
int ans[7]={0,0,0,0,0,0,0};
int A=1,B=0;
int aa[100004];

void fcck(int a,int b,int c,int peo,int cur_sum,int ii) {
	int club_peo[3]={a,b,c};
	if(peo==n) {
		for(int i=0;i<3;i++) {
			if(club_peo[i]>=n/2) continue;
			club_peo[i]++;
			if(ans[ii]<cur_sum+ru[peo][i+1]) ans[ii]=cur_sum+ru[peo][i+1];
		}
		return;
	}
	for(int i=0;i<3;i++) {
		if(club_peo[i]>=n/2) continue;
		club_peo[i]++;
		fcck(club_peo[0],club_peo[1],club_peo[2],peo+1,cur_sum+ru[peo][i+1],ii);
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> num_of_data;
	for(int i=1;i<=num_of_data;i++) {
		cin >> n;
		for(int j=1;j<=n;j++) {
			cin >> ru[j][1] >> ru[j][2] >> ru[j][3];
			aa[j]=ru[j][1];
			if(ru[j][2]!=0&&ru[j][3]!=0) A=0;
		}
		if(A==1) {
			sort(aa,aa+n);
			for(int k=1;k<=n/2;k++) {
				ans[i]+=aa[k];
			}
			continue;
		}
		for(int j=0;j<3;j++) {
			int club_peo[3]={0,0,0};
			club_peo[j]++;
			fcck(club_peo[0],club_peo[1],club_peo[2],1,0,i);
			club_peo[j]--;
		}
	}
	for(int j=1;j<=num_of_data;j++) {
		cout << ans[j] << endl;
	}
	return 0;
}
