#include<bits/stdc++.h>
#define elif else if
using namespace std;
int t,n;
int m[5][55000];
bool c,c2=1,c3=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int s[3]={0,0,0};
	int r[3][17000];
	cin>>t;
	for(int o=1;o<=t;o++){
		int ans=0;
		cin>>n;
		if(n>200)c=1
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[0][i],&m[1][i],&m[2][i]);
			if(c){
				if(m[1][i]!=0){
					c2=0
			}
			if(m[1][i]>=m[2][i]) int l=m[1],ll=1;
			else int l=m[2][i],ll=2;
			if(m[0][i]>=l){
				m[3][i]=m[i][0];
				r[0][s[0]++]=i;
				m[4][i]=0;
			}
			else{
				m[3][i]=l;
				r[ll][s[ll]++]=i;
				m[4][i]=ll;
			}
		}
		if(c){
			if(c2){
				sort(m[0],m[0]+n)
				int ans;
				for(int i=n;i>n/2;i--)ans+=m[0][i];
				cout<<ans<<'\n';
				return 0;
			}
			elif(c3){
				
			}
		} 
		
		int mn;
		for(int i=0;i<3;i++){
			if(s[i]>n/2){
				for(int j=0;j<s[i];j++){
					
				}
			}
		}
		
		//max(m[i][0],max(m[i][1],m[i][2]));
		return 0;
	}
}
