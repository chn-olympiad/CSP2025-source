#include<bits/stdc++.h>
using namespace std;
int tot[100005][4],cmp=0;
int st[6],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int a,b,c;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			tot[j][1]=a;
			tot[j][2]=b;
			tot[j][3]=c;
		}
		while(n--){
			int maxn=0,max3=0;
			for(int j=1;j<=n;j++){
				for(int k=1;k<3;k++){
					maxn=max(tot[j][k],tot[j][k+1]);
				}
				max3=max(maxn,max3);
			}
			sum+=max3;
			max3=0;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=3;k++){
					if(tot[j][k]==max3){
						tot[j][k]=0;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

