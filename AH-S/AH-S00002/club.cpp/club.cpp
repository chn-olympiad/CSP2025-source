#include<bits/stdc++.h>
using namespace std;
int t,n[15],a[100010][13];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n[i]);
		int s=0;
		for(int j=1;j<=n[i];j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3])s+=a[j][1];
			if(a[j][2]>a[j][1]&&a[j][2]>a[j][3])s+=a[j][2];
			if(a[j][3]>a[j][2]&&a[j][3]>a[j][1])s+=a[j][3];
		}
		printf("%d\n",s);
	}
	return 0;
}
