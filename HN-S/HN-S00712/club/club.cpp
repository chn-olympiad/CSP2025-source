#include<bits/stdc++.h>
using namespace std;
int a[100005][5],b[300005][5],s[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c,m;cin>>c;
	for(int i=1;i<=c;i++){
		int n,p[4]={0,0,0,0},x=1,r=0;cin>>n;
		for(int j=1;j<=x;j++){b[j][1]=300005;b[j][2]=0;b[j][3]=0;
		}
		long long ans=0;m=n/2;
		for(int j=1;j<=n;j++){int l[4]={0,0,0,0};
			cin>>a[n][1]>>a[n][2]>>a[n][3];
			for(int k=1;k<=3;k++)if(a[n][1]<=a[n][k])l[1]++;
			for(int k=1;k<=3;k++)if(a[n][2]<=a[n][k])l[2]++;
			l[3]=6-l[1]-l[2];
			s[l[1]]=1;s[l[2]]=2;s[l[3]]=3;
			if(p[s[1]]<m){
				ans+=a[n][s[1]];p[s[1]]++;
			}
			else{for(int o=1;o<x;o++){
			if(a[n][s[1]]-b[o][1]>0&&a[n][s[1]]-b[o][1]>a[n][s[2]]&&b[o][3]==s[1]){
				ans+=a[n][s[1]]-b[o][1];
				b[o][1]=300005;b[o][2]=0;b[o][3]=0;r=1;break;
			}}
			if(r==0){
				ans+=a[n][s[2]];p[s[2]]++;
			}r=0;
			}	b[x][1]=a[n][s[1]]-a[n][s[2]];b[x][2]=n;b[x][3]=s[1];x++;
			for(int y=1;y<x-1;y++)
			for(int k=y;k<x-1;k++){
				if(b[k][1]>b[k+1][1]){
					swap(b[k][1],b[k+1][1]);
					swap(b[k][2],b[k+1][2]);
					swap(b[k][3],b[k+1][3]);
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
