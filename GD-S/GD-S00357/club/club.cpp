#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int s[n][4]={};
		long long sum=0,cnt=0;
		for(int i=0;i<n;i++){
			int maxx=-1;
			for(int j=0;j<3;j++)cin>>s[i][j],maxx=max(maxx,s[i][j]);
			s[i][3]=maxx;}
		for(int i=0;i<n;i++)for(int l=i+1;l<n;l++)if(s[i][3]<s[l][3])swap(s[i],s[l]);
		while(cnt!=n){
			int a=0,b=0,c=0;
			for(int i=0;i<n;i++){
				for(int yy=0;yy<3;yy++){
					int l=0;
					for(;l<3;l++)if(s[i][l]==s[i][3])break;
					if(l==0&&a<n/2){
						a++,cnt++,sum+=s[i][3];
						break;}
					else if(l==1&&b<n/2){
						b++,cnt++,sum+=s[i][3];
						break;}
					else if(l==2&&c<n/2){
						c++,cnt++,sum+=s[i][3];
						break;}
					else{
						int maxx=-1;
						s[i][l]=-1;
						for(l=0;l<3;l++)maxx=max(s[i][l],maxx);
						s[i][3]=maxx;}}}}
		cout<<sum<<'\n';}
	return 0;}
