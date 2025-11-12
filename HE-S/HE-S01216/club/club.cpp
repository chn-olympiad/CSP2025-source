#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	scanf("%d",&n);
	int sum=0;
	int cnt=0;
	int ans=0;
	int d;
	for(int k=1;k<=t;k++){
		for(int x=1;x<=n;x++){
			if(d=='1'){
				sum++;
			}else if(d=='2'){
				cnt++;
			}else if(d=='3'){
				ans++;
			}
		}
		int s=0;
		int w=n/2;
		int a[t][n];
		if(sum<=w&&cnt<=w&&ans<=w){
			for(int i=1;i+1<=n;i++){
				for(int j=1;j<=n;j++){
					cin>>a[i][j];
					if(a[i][j]==d){
						s+=a[i][j];	
						
					}else {
						break;
					}
				}
			}
		}
		printf("%d",s);	
	}
	return 0;
} 
