#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100010][4],A1[100010],A2[100010],A3[100010],i1=0,i2=0,i3=0;
long long ans=0;
bool cmp1(int x,int y){return min(a[x][1]-a[x][2],a[x][1]-a[x][3])>min(a[y][1]-a[y][2],a[y][1]-a[y][3]);}
bool cmp2(int x,int y){return min(a[x][2]-a[x][1],a[x][2]-a[x][3])>min(a[y][2]-a[y][1],a[y][2]-a[y][3]);}
bool cmp3(int x,int y){return min(a[x][3]-a[x][1],a[x][3]-a[x][2])>min(a[y][3]-a[y][1],a[y][3]-a[y][2]);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		i1=0,i2=0,i3=0,ans=0;
		memset(A1,0,sizeof(A1));
		memset(A2,0,sizeof(A2));
		memset(A3,0,sizeof(A3));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) A1[i1]=i,i1++;
			else if(a[i][1]<=a[i][2] && a[i][2]>=a[i][3]) A2[i2]=i,i2++;
			else A3[i3]=i,i3++;
		}
		sort(A1,A1+i1,cmp1);
		sort(A2,A2+i2,cmp2);
		sort(A3,A3+i3,cmp3);
		for(int i=0;i<i1;i++) ans+=a[A1[i]][1];
		for(int i=0;i<i2;i++) ans+=a[A2[i]][2];
		for(int i=0;i<i3;i++) ans+=a[A3[i]][3];
		if(i1>n/2){
			for(int i=n/2;i<=i1;i++) ans=ans-a[A1[i]][1]+max(a[A1[i]][2],a[A1[i]][3]);
		}else if(i2>n/2){
			for(int i=n/2;i<=i2;i++) ans=ans-a[A2[i]][2]+max(a[A2[i]][3],a[A2[i]][1]);
		}else if(i3>n/2){
			for(int i=n/2;i<=i3;i++) ans=ans-a[A3[i]][3]+max(a[A3[i]][2],a[A3[i]][1]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
