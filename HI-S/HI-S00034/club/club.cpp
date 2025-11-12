#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[100005][3],b[3]={0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int x=-1,y=-1,z=-1,num1,num2,num3;
			for(int j=1;j<=3;j++){
				if(a[i][j]>x){
					x=a[i][j];
					num1=j;
				}
				else
				if(a[i][j]>y){
					y=a[i][j];
					num2=j;
				}
				else
				if(a[i][j]>z)
				{
					z=a[i][j];
					num3=j;
				}
			}
			if(b[num1]<=n/2){
				b[num1]++;
				a[i][num1]=0;
				ans+=x;
			}
			else
			if(b[num2]<=n/2){
				b[num2]++;
				a[i][num2]=0;
				ans+=x;
			}
			else
			if(b[num3]<=n/2){
				b[num3]++;
				a[i][num3]=0;
				ans+=x;
			}
			
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
