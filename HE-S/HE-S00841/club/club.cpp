#include <bits/stdc++.h>
using namespace std;
int n;
struct node{int x,y,z;}a[100100];
int ans;
bool cmp1(node x,node y){return x.x>y.x;}
bool cmp2(node x,node y){
	if(x.x!=y.x){return x.x>y.x;}
	else return x.y>y.y;
}
void f(int x,int y,int z,int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(x<n/2)f(x+1,y,z,k+1,sum+a[k].x);
	if(y<n/2)f(x,y+1,z,k+1,sum+a[k].y);
	if(z<n/2)f(x,y,z+1,k+1,sum+a[k].z);
}
int t[5010][5010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		int flag2=0,flag3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0)flag2=1;
			if(a[i].z!=0)flag3=1;
		}
		if(!flag3){
			if(!flag2){
				sort(a+1,a+1+n,cmp1);
				int sum=0;
				for(int i=n;i>n/2;i--)sum+=a[i].x;
				cout<<sum<<endl;
				continue;
			}
			else{
				t[1][0]=a[1].x,t[0][1]=a[1].y;
				for(int d=2;d<=n;d++){
					if(d>=n/2){
						for(int i=0;n/2-i>1&&d-n/2+i<=n/2;i++){
//							cout<<n/2-i<<" "<<d-n/2+i<<endl;
							t[n/2-i][d-n/2+i]=max(max(t[n/2-i-1][d-n/2+i]+a[d].x,
												  t[n/2-i][d-n/2+i-1]+a[d].y),t[n/2-i][d-n/2+i]);
						}
					}
					else{
						for(int i=1;d-i>1&&i<=n/2;i++){
//							cout<<i<<" "<<d-i<<endl;
							t[i][d-i]=max(max(t[i-1][d-i]+a[d].x,
							              t[i][d-i-1]+a[d].y),t[i][d-i]);
						}
					}
				}
				cout<<t[n/2][n/2]<<endl;
				continue;
			}
		}
		else if(n<=20)f(0,0,0,1,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 25
