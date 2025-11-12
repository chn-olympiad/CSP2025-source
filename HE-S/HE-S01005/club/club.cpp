#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[110001][6],sum=0,m[100100],c[5],l[100101],minn=9999,cc[100111][5],bb[100111][6];
int b[10];

int two(){
	for(int i=1;i<=2;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		for(int i=1;i<=3;i++){
			for(int k=1;k<=3;k++){
				if(i!=k){
					sum=max(a[1][i]+a[2][k],sum);
				}
				
			}
		}
		return sum;
		}
int main(){
	freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
	memset(m,-1,sizeof m);
	cin>>t;
	memset(cc,0,sizeof cc);
	memset(bb,0,sizeof bb);
	memset(m,-1,sizeof m);
	memset(b,-1,sizeof b);
	for(int h=0;h<t;h++){
		cin>>n;
		sum=0;
			memset(cc,0,sizeof cc);
	memset(bb,0,sizeof bb);
	memset(m,-1,sizeof m);
	memset(b,-1,sizeof b);
		if(n==2){
			two();
		}else{
			for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[1]=a[i][1];
			b[2]=a[i][2];
			b[3]=a[i][3];
			
			sort(b+1,b+4);
		
			for(int k=1;k<=3;k++){
				for(int j=1;j<=3;j++){
					if(a[i][k]==b[j]){
					cc[i][j]=k;
					bb[i][j]=b[j];
				}
				}
				
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int p=1;p<=3;p++)
			{
				if(a[k][p]>m[k]){
					m[k]=a[k][p];
					c[k]=p;
				}
				
			
			
			}
				sum+=m[k];		
				l[c[k]]++;
				if(l[c[k]]>n/2){
					for(int i=1;i<=k;i++){
						if(c[i]==c[k]){
							minn=min(minn,m[i]);
						
						}
						
					}
					sum-=minn;
				
					for(int i=1;i<=k;i++){
						if(m[i]==minn){
						
							m[i]=bb[i][2];
							c[i]=cc[i][2];
							sum+=m[i];
						
							break;
						}
						
					}
					
					l[c[k]]--;
			}
		}
		}
	
		cout<<sum<<endl;
			memset(cc,0,sizeof cc);
	memset(l,0,sizeof l);
	memset(m,-1,sizeof m);
	memset(b,-1,sizeof b);
	}
	
	
	return 0;
}
