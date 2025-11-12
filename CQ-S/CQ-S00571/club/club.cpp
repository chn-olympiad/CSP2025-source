#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin.tie(),cout.tie();
    int T;
    cin>>T;
    while(T--){
    	int n,v[4];
        cin>>n;
		int a[n+9][3],k[n*3+9][7],f=n/2;
		memset(k,0,sizeof(k));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int l=1;l<=3;l++){
				for(int j=0;j<i;j++){
					for(int s=1;s<=3;s++){
						if(k[j][l+1]<=f&&k[i][s+4]<a[i][l]+k[j][1]){
                    	    for(int go=1;go<5;go++)k[i][go]=k[j][go];
                    	    k[i][l+1]++;
                    	    k[i][s+4]=k[i][1]=k[i][1]+a[i][l];
					    }
				    }
			    }
		    }
	    }
	    cout<<k[n][1];
    }
	return 0;
} 
