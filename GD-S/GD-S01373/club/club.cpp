#include<bits/stdc++.h>
using namespace std;


int n;
int a[100010][4];
int que1[50010],que2[50010],que3[50010];
int h1=0,h2=0,h3=0,t1=1,t2=1,t3=1;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n); 
		

		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				que1[t1]=a[i][1];t1++;
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
