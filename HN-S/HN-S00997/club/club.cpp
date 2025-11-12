#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    int a[3];
    int p=n/2;
    int num=0;
    int x=0,y=0,z=0;
    int maxn;
    while(t--){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3){
    			cin>>a[j];
			}
			maxn=a[1];
			for(int j=1;j<=3;j++){
				if(maxn<a[j]){
					maxn=a[j];
				}
			}
			for(int j=1;j<=3;j++){
				if(a[j]==maxn){
					if(x<p){
						if(j==1){
							x+=1;
						}
					}
					if(y<p){
						if(j==2){
							y+=1; 
						}
					}
					if(z<p){
						if(j==3){
							z+=1;
						}
					}
				}
			}
		}
	}
	return 0;
}

