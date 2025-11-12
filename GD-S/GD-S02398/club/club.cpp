#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;

LL a[100010][100010];

LL Max(int a,int b,int c){
	if(a>=b && a>=c){
		return a;
	}else if(b>=a && b>=c){
		return b;
	}else{
		return c;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t){
		LL n,ans=0;
		cin>>n;
		LL lis[5],top=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		
		for(int i=1;i<=n;i++){
			if(Max(a[i][1],a[i][2],a[i][3])==a[i][1]){
				if(lis[1]<top){
					lis[1]++;
					ans+=a[i][1];
				}
				else if(lis[2]<top && a[i][2]>a[i][3] || lis[3]>=top  && lis[2]<top){
					lis[2]++;
					ans+=a[i][2];
				}
				else if(lis[3]<top && a[i][3]>a[i][2] || lis[2]>=top && lis[3]<top){
					lis[3]++;
					ans+=a[i][3];
				}
			}
			else if(Max(a[i][1],a[i][2],a[i][3])==a[i][2]){
				if(lis[2]<top){
					lis[2]++;
					ans+=a[i][2];
				}
				else if(lis[1]<top && a[i][1]>a[i][3] || lis[3]>=top && lis[1]<top){
					lis[1]++;
					ans+=a[i][1];
				}
				else if(lis[3]<top && a[i][3]>a[i][1] || lis[1]>=top && lis[3]<top){
					lis[3]++;
					ans+=a[i][3];
				}
			}
			else if(Max(a[i][1],a[i][2],a[i][3])==a[i][3] && lis[3]<top){
				if(lis[3]<top){
					lis[3]++;
					ans+=a[i][3];
				}
				else if(lis[1]<top && a[i][1]>a[i][2] || lis[1]>=top && lis[2]<top){
					lis[1]++;
					ans+=a[i][1];
				}
				else if(lis[2]<top && a[i][2]>a[i][1] || lis[1]>=top && lis[2]<top){
					lis[2]++;
					ans+=a[i][2];
				}
			}
			
		}
		
		
		cout<<ans<<endl;
		t--;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
