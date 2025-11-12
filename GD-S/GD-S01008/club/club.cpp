#include<bits/stdc++.h>
using namespace std;
int n,m,a1;
int b,c,d;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int ans[n];
	for(int s=1;s<=n;s++){
		cin>>m;
		int s1[m],s2[m],s3[m];
		int a[3][m];
		for(int i=1;i<=3;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int j=1;j<=m;j++){
			for(int i=1;i<=3;i++){
				if(max(max(a[i][j],a[i+1][j]),a[i+2][j])==a[i][j]){
					if(b<=m/2) s1[j]=a[i][j],b++; 
					else{
						if(max(a[i+1][j],a[i+2][j])==a[i+1][j]) s2[j]=a[i][j+1];
						if(max(a[i+1][j],a[i+2][j])==a[i+2][j]) s3[j]=a[i][j+2];
					}

				}
				if(max(max(a[i][j],a[i+1][j]),a[i+2][j])==a[i+1][j]){
					if(c<=m/2) s2[j]=a[i+1][j],c++;
					else{
						if(max(a[i][j],a[i+2][j])==a[i][j]) s1[j]=a[i][j];
						if(max(a[i][j],a[i+2][j])==a[i][j+2]) s3[j]=a[i+2][j];
					}

				}
				if(max(max(a[i][j],a[i+1][j]),a[i+2][j])==a[i+2][j]){
					if(d<=m/2) s3[j]=a[i+2][j],d++;
					else{
						if(max(a[i+1][j],a[i][j])==a[i+1][j]) s2[j]=a[i+1][j];
						if(max(a[i+1][j],a[i][j])==a[i][j]) s1[j]=a[i][j];
					}

				}
				
			}
		}
		for(int i=1;i<=m;i++) a1=a1+s1[i]+s2[i]+s3[i],cout<<endl<<a1;
		ans[s]=a1;
		a1=0,m=0;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
} 
