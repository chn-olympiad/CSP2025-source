#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		int s[n][3],v[3][n];
		int a[3]={-1,-1,-1};
		for(int i=0;i<n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			if(s[i][0]>max(s[i][1],s[i][2])) v[0][++a[0]]=i,ans+=s[i][0];
			else if(s[i][1]>s[i][2]) v[1][++a[1]]=i,ans+=s[i][1];
			else v[2][++a[2]]=i,ans+=s[i][2];
		}
		bool p;
		do{
			p=false;
			for(int i=0;i<3;i++){
				while(a[i]>=n/2){
					int x=(i+2)%3,y=(i+4)%3;
					int MIN=0;
					for(int j=0;j<=a[i];j++){
						if(min(s[v[i][j]][i]-s[v[i][j]][x],s[v[i][j]][i]-s[v[i][j]][y])<min(s[v[i][MIN]][i]-s[v[i][MIN]][x],s[v[i][MIN]][i]-s[v[i][MIN]][y])) MIN=j;
					}
					if(s[v[i][MIN]][x]>s[v[i][MIN]][y]){ ans+=s[v[i][MIN]][x],++a[x];}
					else {ans+=s[v[i][MIN]][y],++a[y];}
					ans-=s[v[i][MIN]][i];
					swap(v[i][MIN],v[i][a[i]]);
					--a[i];
					p=true;
				}
			}
		}while(p);
		cout<<ans<<endl;
	}
	return 0;
}
