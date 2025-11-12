#include<bits/stdc++.h>
using namespace std;
const long long jj=300000;
long long a,s[500010][2][2],d,f,g,h,j,k,l,n,q,ans;
void read(int x,int c){
	char ff=getchar();
	int cnt=0;
	while(ff!='a'&&ff!='b') ff=getchar();
	while(ff!='a'){
		ff=getchar();
		cnt++;
	}
	s[x][c][1]=cnt; //a的左边有多少b 
	cnt+=2;
	ff=getchar();
	while(ff=='b'){
		ff=getchar();
		cnt++;
	}
	s[x][c][0]=cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		read(i,0);
		read(i,1);
	}
	for(int i=1;i<=q;i++){
		ans=0;
		read(jj,0);
		read(jj,1);
		if(s[jj][0][0]!=s[jj][1][0]) cout<<0<<'\n';
		else{
			for(int i=1;i<=n;i++){
				if(s[jj][0][1]>=s[i][0][1]&&(s[jj][0][0]-s[jj][0][1])>=(s[i][0][0]-s[i][0][1])&&((s[i][0][1]-s[i][1][1])==(s[jj][0][1]-s[jj][1][1]))) ans++;
			}
			cout<<ans<<'\n';
		}
	}
}
