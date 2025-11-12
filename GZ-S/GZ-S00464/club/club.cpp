#include<bits/stdc++.h>// GZ-S00464；陈宣谕；毕节梁才学校 

using namespace std;

int t;
int n;
int a[100010][10];
int cnt[10];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
    	for(int j=0;j<n;j++){
	    	for(int k=0;k<3;k++){
		    	scanf("%d",&a[j][k]);
		    }
	    }
	}
	for(int i=0;i<n;i++){
	    int ans=0;
		for(int j=0;j<3;j++){
			int ma=-0x3f3f3f3f;
			ma=max(ma,a[i][j]);
	    	ans+=ma;
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
