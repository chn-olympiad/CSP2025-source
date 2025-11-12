//GZ-S00221 铜仁一中初级中学 李宇轩 
#include<bits/stdc++.h>
using namespace std;
int n,a[10000][5],d1,d2,d3,s1,s2,s3,t;
int c1[10000],c2[10000],c3[10000],sum;
void stc(int n1,int n2,int n3,int sx1,int sx2,int sx3,
int l1[10000],int l2[10000],int l3[10000],int m1,int m2,int m3){
	if(n1 > n/2){
		sort(l1,l1+n1+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(l1[1] == a[i][sx1]){
					if(a[i][sx2] > a[i][sx3]){
						n2++;
						l2[n2] = l1[1];
						l1[1] = 1000000;
						sort(l1,l1+n1+1);
						n1--;
						m2 += a[i][sx2];
						m1 -= a[i][sx1];
						break;
					}
					else{
						n3++;
						l3[n3] = l1[1];
						l1[1] = 1000000;
						sort(l1,l1+n1+1);
						n1--;
						m3 += a[i][sx3];
						m1 -= a[i][sx1];
						break;
					}
				}
			}
		}
		stc(n1,n2,n3,sx1,sx2,sx3,l1,l2,l3,m1,m2,m3);
	}
	else{
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				d1 += a[i][1];
				s1++;
				c1[s1] = a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				d2 += a[i][2];
				s2++;
				c2[s2] = a[i][2];
			}
			else{
				d3 += a[i][3];
				s3++;
				c3[s3] = a[i][3];
			}
		}
		stc(s1,s2,s3,1,2,3,c1,c2,c3,d1,d2,d3);
		stc(s2,s1,s3,2,1,3,c2,c1,c3,d2,d1,d3);
		stc(s3,s1,s2,3,1,2,c3,c1,c2,d3,d1,d2);
		cout<<d1+d2+d3<<endl;
		d1=0,d2=0,d3=0,s1=0,s2=0,s3=0,sum=0;
		c1[10000]=0,c2[10000]=0,c3[10000]=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
