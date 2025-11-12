#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][5],f[100010],m[100010],ans,tmp;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(m,0,sizeof(m));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			tmp=max(a[i][1],a[i][2]);
			if(tmp==a[i][1]){
				m[1]++;
			}
			else m[2]++;
			ans+=tmp;

		} 
		if(m[1]==(n/2)) cout<<ans<<endl;
		else{
			for(int i=1;i<=3;i++){
				if(m[i]>(n/2)){
					if(i==1){
						for(int j=1;j<=n;j++){
							if(a[j][1]<a[j][2]) f[j]=0x3f;
							else f[j]=a[j][1]-a[j][2];
						}
						sort(f+1,f+1+n);
						for(int j=1;j<=(m[i]-(n/2));j++){
							ans-=f[j];
						}
						cout<<ans<<endl;
						break;
					}
					else{
						for(int j=1;j<=n;j++){
							if(a[j][2]<a[j][1]) f[j]=0x3f;
							f[j]=a[j][2]-a[j][1];
						}
						sort(f+1,f+1+n);
						for(int j=1;j<=(m[i]-(n/2));j++){
							ans-=f[j];
						}
						cout<<ans<<endl;
						break;					
					}
					
				}
			}
				
		}

	}
	
	return 0;
}

