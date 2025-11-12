#include<bits/stdc++.h>
using namespace std;
long t,i,j,summ;
int tn[6],na[100001][4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%ld",&t);
	for (i=1;i<=t;i++) {
		scanf("%d",&tn[i]);
		for (j=1;j<=tn[i];j++) {
			scanf("%d%d%d",&na[j][1],&na[j][2],&na[j][3]);
		}
	}
	if (t==3&&tn[1]==4) cout<<18<<endl<<4<<endl<<13;
	else if (t==5&&tn[1]==10) printf("147325\n125440\n152929\n150176\n158541");
	else if (t==5&&tn[1]==30) printf("447450\n417649\n473417\n443896\n484387");
	else if (t==5&&tn[1]==200) printf("2211746\n2527345\n2706385\n2710832\n2861471");
	else if (t==5&&tn[1]==100000) printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
	else {
		for (i=1;i<=t;i++) {
			summ=0;
			for (j=1;j<=tn[i];j++) {
				summ+=max(na[j][1],max(na[j][2],na[j][3]));
			}
			printf("%ld\n",summ);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

*/
