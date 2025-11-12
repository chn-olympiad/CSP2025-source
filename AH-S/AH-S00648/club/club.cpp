#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N][4],firb[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int x=0,y=0,z=0;
		int seca[N],secb[N],secc[N];
		memset(a,0,sizeof(a));
		memset(firb,0,sizeof(firb));
		memset(secb,0,sizeof(secb));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]) firb[i]=a[i][1],seca[x+1]=a[i][1]-a[i][2],x++;
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]) firb[i]=a[i][1],seca[x+1]=a[i][1]-a[i][3],x++;
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]) firb[i]=a[i][2],secb[y+1]=a[i][2]-a[i][1],y++;
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]) firb[i]=a[i][2],secb[y+1]=a[i][2]-a[i][3],y++;
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]) firb[i]=a[i][3],secc[z+1]=a[i][3]-a[i][1],z++;
			else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]) firb[i]=a[i][3],secc[z+1]=a[i][3]-a[i][2],z++;
		}
		sort(seca+1,seca+x+1);
		sort(secb+1,secb+y+1);
		sort(secc+1,secc+z+1);
		int tot=0,jian=0;
		for(int j=1;j<=n;j++){
			tot+=firb[j];
		}
		if(x>n/2){
			for(int q=1;q<=x-n/2;q++) jian+=seca[q];
		}
		else if(y>n/2){
			for(int q=1;q<=y-n/2;q++) jian+=secb[q];
		}
		else if(z>n/2){
			for(int q=1;q<=z-n/2;q++) jian+=secc[q];
		}
		cout<<tot-jian<<endl;
	}
	return 0;
}
