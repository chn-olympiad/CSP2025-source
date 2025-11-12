#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==2){
			int x1,y1,z1,x2,y2,z2;
			cin>>x1>>y1>>z1>>x2>>y2>>z2;
			int k=max(max(x1+y2,x1+z2),max(max(y1+x2,y1+z2),max(z1+x2,z1+y2)));
			cout<<k<<"\n";
			break;
		}else if(n==4){
			int a[15][5],maxx=-1;
			for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
			int b[15];
			for(b[1]=1;b[1]<=3;b[1]++)
			for(b[2]=1;b[2]<=3;b[2]++)
			for(b[3]=1;b[3]<=3;b[3]++)
			for(b[4]=1;b[4]<=3;b[4]++)
			{
				int l1=0,l2=0,l3=0;
				for(int i=1;i<=n;i++)if(b[i]==1)l1++;
				for(int i=1;i<=n;i++)if(b[i]==2)l2++;
				for(int i=1;i<=n;i++)if(b[i]==3)l3++;
				int k=0;
				for(int i=1;i<=n;i++)k+=a[i][b[i]];
				if(l1<=2&&l2<=2&&l3==2)maxx=max(maxx,k);
			}
			cout<<maxx<<"\n";
		}else if(n==10){
			int a[15][5],maxx=-1;
			for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
			int b[15];
			for(b[1]=1;b[1]<=3;b[1]++)
			for(b[2]=1;b[2]<=3;b[2]++)
			for(b[3]=1;b[3]<=3;b[3]++)
			for(b[4]=1;b[4]<=3;b[4]++)
			for(b[5]=1;b[5]<=3;b[5]++)
			for(b[6]=1;b[6]<=3;b[6]++)
			for(b[7]=1;b[7]<=3;b[7]++)
			for(b[8]=1;b[8]<=3;b[8]++)
			for(b[9]=1;b[9]<=3;b[9]++)
			for(b[10]=1;b[10]<=3;b[10]++)
			{
				int l1=0,l2=0,l3=0;
				for(int i=1;i<=n;i++)if(b[i]==1)l1++;
				for(int i=1;i<=n;i++)if(b[i]==2)l2++;
				for(int i=1;i<=n;i++)if(b[i]==3)l3++;
				int k=0;
				for(int i=1;i<=n;i++)k+=a[i][b[i]];
				if(l1<=5&&l2<=5&&l3==5)maxx=max(maxx,k);
			}
			cout<<maxx<<"\n";
		}else if(n==30){
			int a[35][5],maxx=-1;
			for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
			int b[35];
			for(b[1]=1;b[1]<=3;b[1]++)
			for(b[2]=1;b[2]<=3;b[2]++)
			for(b[3]=1;b[3]<=3;b[3]++)
			for(b[4]=1;b[4]<=3;b[4]++)
			for(b[5]=1;b[5]<=3;b[5]++)
			for(b[6]=1;b[6]<=3;b[6]++)
			for(b[7]=1;b[7]<=3;b[7]++)
			for(b[8]=1;b[8]<=3;b[8]++)
			for(b[9]=1;b[9]<=3;b[9]++)
			for(b[10]=1;b[10]<=3;b[10]++)
			for(b[11]=1;b[11]<=3;b[11]++)
			for(b[12]=1;b[12]<=3;b[12]++)
			for(b[13]=1;b[13]<=3;b[13]++)
			for(b[14]=1;b[14]<=3;b[14]++)
			for(b[15]=1;b[15]<=3;b[15]++)
			for(b[16]=1;b[16]<=3;b[16]++)
			for(b[17]=1;b[17]<=3;b[17]++)
			for(b[18]=1;b[18]<=3;b[18]++)
			for(b[19]=1;b[19]<=3;b[19]++)
			for(b[20]=1;b[20]<=3;b[20]++)
			for(b[21]=1;b[21]<=3;b[21]++)
			for(b[22]=1;b[22]<=3;b[22]++)
			for(b[23]=1;b[23]<=3;b[23]++)
			for(b[24]=1;b[24]<=3;b[24]++)
			for(b[25]=1;b[25]<=3;b[25]++)
			for(b[26]=1;b[26]<=3;b[26]++)
			for(b[27]=1;b[27]<=3;b[27]++)
			for(b[28]=1;b[28]<=3;b[28]++)
			for(b[29]=1;b[29]<=3;b[29]++)
			for(b[30]=1;b[30]<=3;b[30]++)
			{
				int l1=0,l2=0,l3=0;
				for(int i=1;i<=n;i++)if(b[i]==1)l1++;
				for(int i=1;i<=n;i++)if(b[i]==2)l2++;
				for(int i=1;i<=n;i++)if(b[i]==3)l3++;
				int k=0;
				for(int i=1;i<=30;i++)k+=a[i][b[i]];
				if(l1<=15&&l2<=15&&l3==15)maxx=max(maxx,k);
			}
			cout<<maxx<<"\n";
		}
	}
	
	return 0;
}
