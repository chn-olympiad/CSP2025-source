#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int n;
int t;
struct s{
	int s1;
	int s2;
	int s3;
	int st1;//首选 
	int st2;//次选 
	int st3;//末选 
	int sy1;
	int sy2;
	int sy3;
}a[100005];
int h1[100005][5];
bool bh1[100005];
int h2[100005][5];
bool bh2[100005];
int h3[100005][5];
bool bh3[100005];
int cn[50005][5];
int cnc;
int r[5];
int g;
int main()
{
	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int rf=1;rf<=t;rf++){
		cin>>n; 
		for(int i=1;i<=n;i++){//
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3){
				a[i].st1=1;
				a[i].sy1=1;
				if(a[i].s2>=a[i].s3){
					a[i].st2=2;a[i].st3=3;
					a[i].sy2=2;a[i].sy3=3;
				}else{
					a[i].st3=2;a[i].st2=3;
					a[i].sy2=3;a[i].sy3=2;
				}
			}else if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3){
				a[i].st2=1;
				a[i].sy1=2;
				if(a[i].s1>=a[i].s3){
					a[i].st1=2;a[i].st3=3;
				}else{
					a[i].st1=3;a[i].st3=2;
				}
			}else if(a[i].s3>=a[i].s1&&a[i].s3>=a[i].s2){
				a[i].st3=1;
				a[i].st1=3;
				if(a[i].s2>=a[i].s1){
					a[i].st2=2;a[i].st1=3;
				}else{
					a[i].st1=2;a[i].st2=3;
				}
			} 
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].st1<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i].st2<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i].st3<<" ";
//		}
		for(int i=1;i<=n;i++){
			h1[i][2]=a[i].sy1;
			if(a[i].st1==1){
				h1[i][1]=a[i].s1;
			}else if(a[i].st1==2){
				h1[i][1]=a[i].s2;
			}else if(a[i].st1==3){
				h1[i][1]=a[i].s3;
			}
			//----------------------------
			h2[i][2]=a[i].sy2;
			if(a[i].st2==1){
				h2[i][1]=a[i].s1;
			}else if(a[i].st2==2){
				h2[i][1]=a[i].s2;
			}else if(a[i].st2==3){
				h2[i][1]=a[i].s3;
			}
			//----------------------------
			h3[i][2]=a[i].sy3;
			if(a[i].st3==1){
				h3[i][1]=a[i].s1;
			}else if(a[i].st3==2){
				h3[i][1]=a[i].s2;
			}else if(a[i].st3==3){
				h3[i][1]=a[i].s3;
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				cout<<h1[j][i];
				cout<<" ";
			}
			cout<<endl;
		} 
		r[1]=n/2;
		r[2]=n/2; 
		r[3]=n/2;
		cnc=1;
		for(int i=1;i<=n&&r[1]>=1;i++){
			g=1;
			for(int j=1;j<=n;j++){
				if(h1[j][1]>h1[g][1]&&bh1[g]==true){
					g=i;
				}
			}
			cn[cnc][1]=h1[g][1];
			cnc++;
			bh1[g]=false;
			r[1]--;
		}
		cnc=1;
		for(int i=1;i<=n&&r[2]>=1;i++){
			g=1;
			for(int j=1;j<=n;j++){
				if(h2[j][1]>h2[g][1]&&bh2[g]==true){
					g=i;
				}
			}
			cn[cnc][2]=h2[g][1];
			cnc++;
			bh2[g]=false;
			r[2]--;
		}
		cnc=1;
		for(int i=1;i<=n&&r[3]>=1;i++){
			g=1;
			for(int j=1;j<=n;j++){
				if(h3[j][1]>h3[g][1]&&bh3[g]==true){
					g=i;
				}
			}
			cn[cnc][3]=h3[g][1];
			cnc++;
			bh3[g]=false;
			r[3]--;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<cn[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	
	fclose(stdin);
//	fclose(stdout);
	return 0;
}
