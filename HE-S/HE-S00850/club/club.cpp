#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t){
		int n,sum=0;
		scanf("%lld",&n);
		if(n==2){
			int a,b,c,x,y,z;
			cin>>a>>b>>c>>x>>y>>z;
			sum=max(sum,a+y);
			sum=max(sum,a+z);
			sum=max(sum,b+x);
			sum=max(sum,b+z);
			sum=max(sum,c+x);
			sum=max(sum,c+y);
			cout<<sum<<endl;
		}
		else{
			int a[10005],b,c,y=0,z=0,l[100005][4];
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i],&b,&c);
				if(b==0){
					y++;
				}
				if(c==0){
					z++;
				}
				l[i][1]=a[i];
				l[i][2]=b;
				l[i][3]=c;
			}
			if(y==n&&z==n){
				sort(a+1,a+n+1,greater<int>());
				for(int i=1;i<=n/2;i++){
					sum+=a[i];
				}
				cout<<sum<<endl;
			}
			else if(y==n){
				sort(a+1,a+n+1,greater<int>());
				for(int i=1,j=1;i<=n/2,j<=n/2;i++,j++){
					sum+=max(a[i],b[l][2]);
				}
			}
			else{
				for(int i=1;i<=n;i++){
					sum+=max(l[i][1],max(l[i][2],l[i][3]));
				}
				cout<<sum<<endl;
			}
		}
		t--;
	}
	freclose(stdin);
	freclose(stdout);
	return 0;
}
