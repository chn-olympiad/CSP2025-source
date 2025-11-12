#include<bits/stdc++.h>
using namespace std;
int ma,t,n;
long long ans;
struct person{
	int x,y,z;
}a[100010];
int b[100010][4];
int v[5];
bool cmp(person b,person c){
	return b.x>c.x;
}
void cheak(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(j!=i){
				ans=max(ans,(long long)(b[1][i]+b[2][j]));
			}
			

		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		ans=0;
		cin>>n;
		ma=n/2;
		bool f=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0||a[i].z!=0){
				f=false;
			}
		}
		
		if(f){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(i<=ma)ans+=a[i].x;
			}
			cout<<ans<<endl;;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			b[i][1]=a[i].x;
			b[i][2]=a[i].y;
			b[i][3]=a[i].z;
		}
		if(n==2){
			int pos;
			cheak();
			cout<<ans;
			continue;
		}
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			int x=0,p=0;
			
			for(int j=1;j<=3;j++){
				if(v[j]<ma){
					if(b[i][j]>x){
						p=j;
						x=b[i][j];
					}
				}
				
			}
			v[p]++;
			ans+=x;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

