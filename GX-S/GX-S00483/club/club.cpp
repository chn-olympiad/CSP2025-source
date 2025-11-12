#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int cs=0;cs<t;cs++){
		int n,ans=0;
		cin>>n;
		int a[n][3],guang[3*n+1][3];
		bool ru[n];
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ru[i]=true;
		}
		int num=0;
		for(int i=0;i<n;i++){
			for(int p=0;p<3;p++){
				guang[num][0]=i;
				guang[num][1]=p;
				guang[num][2]=a[i][p];
				num++;
			}
		}
		for(int i=0;i<num;i++){
			for(int p=i;p<num;p++){
				if(guang[i][2]<guang[p][2]){
					int p1=guang[i][1];
					int p2=guang[i][2];
					int p0=guang[i][0];
					guang[i][0]=guang[p][0];
					guang[[i][1]=guang[p][1];
					guang[i][2]=guang[p][2];
					guang[p][0]=p0;
					guang[p][1]=p1;
					guang[p][2]=p2;
				}
			}
		}
		int st[3]={n/2,n/2,n/2};
		for(int i=0;i<num;i++){
			if(st[guang[i][1]]&&ru[guang[i][0]]){
				ans+=guang[i][2];
				st[guang[i][1]]--;
				ru[guang[i][0]]=false;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
