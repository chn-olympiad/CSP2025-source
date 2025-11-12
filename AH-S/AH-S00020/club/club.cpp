#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],re1[100005],re2[100005],re3[100005],ct[3],ab1,ab2,ab3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf ("%d",&n);
		for(int i=0;i<n;i++)	scanf ("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		memset(re1,0,sizeof(re1));memset(re2,0,sizeof(re2));
		memset(re3,0,sizeof(re3));ct[0]=0;ct[1]=0;ct[2]=0;ab1=0;ab2=0;ab3=0;
		int sum=0,ss=0;
		for(int i=0;i<n;i++){
			int a1=max(a[i][0],max(a[i][1],a[i][2])),a2;
			if(a1==a[i][0]){a2=max(a[i][1],a[i][2]);ct[0]++;re1[ab1++]=a1-a2;sum+=a1;}
			else if(a1==a[i][1]){a2=max(a[i][0],a[i][2]);ct[1]++;re2[ab2++]=a1-a2;sum+=a1;}
			else{a2=max(a[i][0],a[i][1]);ct[2]++;re3[ab3++]=a1-a2;sum+=a1;}
		}
		if(ct[0]<=n/2&&ct[1]<=n/2&&ct[2]<=n/2);
		else if(ct[0]>n/2){
			sort(re1,re1+ab1);
			for(int i=0;i<ct[0]-n/2;i++)	ss+=re1[i];
		}
		else if(ct[1]>n/2){
			sort(re2,re2+ab2);
			for(int i=0;i<ct[1]-n/2;i++)	ss+=re2[i];
		}
		else{
			sort(re3,re3+ab3);
			for(int i=0;i<ct[2]-n/2;i++)	ss+=re3[i];
		}
		printf ("%d\n",sum-ss);
	}
	return 0;
}
