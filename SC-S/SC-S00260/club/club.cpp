#include<bits/stdc++.h>
using namespace std;

int t,n,a[100005][3],p[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","s",stdout);
	scanf("%d",&t);
	int sum=0,ans1=0,ans2=0,ans3=0; 
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[k][j]); 
			}
			if(a[k][1]>a[k][2]&&a[k][1]>a[k][3]){
				p[1]++;
				ans1+=a[k][1]; 
			}
			else if(a[k][2]>a[k][1]&&a[k][2]>a[k][3]){
				p[2]++;
				ans2+=a[k][2];
			}
			else if(a[k][3]>a[k][2]&&a[k][3]>a[k][1]){
				p[3]++;
				ans3+=a[k][3];
			} 
		}
		printf("%d\n",ans1+ans2+ans3);
		ans1=0;ans2=0;ans3=0;
	}		
	return 0;
} 