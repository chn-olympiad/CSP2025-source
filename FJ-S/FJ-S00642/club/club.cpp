#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long d[190050][4],d2[190050][4],d3[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		long long num2=0;
		for(int i=1;i<=130050;i++){
			for(int j=1;j<=3;j++)
			{
				d[i][j]=0;
				d2[i][j]=0;
			}
		}
		for(int i=1;i<=3;i++) d3[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>d[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int cnt=1;
			if(d[i][1]<d[i][2]){
				if(d[i][2]<d[i][3])cnt=3;
				else cnt=2;
			}
			else if(d[i][1]<d[i][3])cnt=3;
			
			if(d3[cnt]<(n>>1)){
				
				//d2[i][cnt]=d[i][cnt];
				d3[cnt]++;
				d2[d3[cnt]][cnt]=d[i][cnt];
			}

			else{
				int o=1;
				long long ttt=100000000000;
				for(int p=1;p<=d3[cnt];p++)
				{
					//if(d3[cnt]==1)break;
					if(ttt>d2[p][cnt])o=p;
					ttt=min(ttt,d2[p][cnt]);
				}
//				for(int p=1;p<=2;p++)
//				{
//					int q=(cnt+p)%4;
//					if()
//					if(d3[q]<(n>>1)){
//						d2[d3[q]+1][q]=d[o][q];
//						break;
//					}
//				}
				int q=0;
				if(d[o][(cnt+1)%4]>d[o][(cnt+2)%4]&&d3[(cnt+1)%4]<(n>>1)){
					 q=(cnt+1)%4;
					d2[d3[q]+1][q]=d[o][q];
				}
				else if (d3[(cnt+2)%4]<(n>>1))
				 {
				  q=(cnt+2)%4;
				  d2[d3[q]+1][q]=d[o][q];
			
				}
				d2[o][cnt]=d[i][cnt];
			}
		}
			for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) {
				//if(d2[i][j]!=0){
					num2+=d2[i][j];
				//}
		}
		}
		cout<<num2<<endl;
	}
	
	return 0;
}
