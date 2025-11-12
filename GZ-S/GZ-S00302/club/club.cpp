//GZ-S00302 都匀二中 潘祖镇 
#include<bits/stdc++.h>
using namespace std;
int t,n[6],m[100005][4]={0};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		int ANS=0,a[n[i]][4],temp;
		for(int j=1;j<=n[i];j++){
			cin>>m[j][1]>>m[j][2]>>m[j][3];
			a[j][1]=1;a[j][2]=2;a[j][3]=3;
			if(m[j][2]>m[j][1]){
				temp=a[j][1];
				a[j][1]=a[j][2];
				a[j][2]=temp;
			}
			if(m[j][3]>m[j][1]){
				temp=a[j][1];
				a[j][1]=a[j][3];
				a[j][3]=temp;
			}
			if(m[j][3]>m[j][2]){
				temp=a[j][2];
				a[j][2]=a[j][3];
				a[j][3]=temp;
			}
			int min=a[1][1],MIN=1;
			for(int k=2;k<=j;k++){
				if(m[j][a[j][1]]<m[MIN][min]){
					MIN=j;
					min=a[j][1];
				}
			}
			if(m[0][a[j][1]]==n[i]/2&&m[j][a[j][1]]>m[MIN][min]){
				ANS-=m[MIN][min];
				m[0][min]--;
				ANS+=m[j][a[j][1]];
				m[0][a[j][1]]++;
			}
			else if(m[0][a[j][1]]<n[i]/2){
				ANS+=m[j][a[j][1]];
				m[0][a[j][1]]++;
			}
			else if(m[0][a[j][2]]==n[i]/2&&m[j][a[j][2]]>m[MIN][min]){
				ANS-=m[MIN][min];
				m[0][min]--;
				ANS+=m[j][a[j][2]];
				m[0][a[j][2]]++;
			}
			else if(m[0][a[j][2]]<n[i]/2){
				ANS+=m[j][a[j][2]];
				m[0][a[j][2]]++;
			}
			else if(m[0][a[j][3]]==n[i]/2&&m[j][a[j][3]]>m[MIN][min]){
				ANS-=m[MIN][min];
				m[0][min]--;
				ANS+=m[j][a[j][3]];
				m[0][a[j][3]]++;
			}
			else if(m[0][a[j][3]]<n[i]/2){
				ANS+=m[j][a[j][3]];
				m[0][a[j][3]]++;
			}
			
		}
		
	cout<<ANS<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
