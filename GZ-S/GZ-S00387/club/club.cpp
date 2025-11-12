//GZ-J00387 贵阳市第二实验中学 范思杨 
#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int a[100005][6],s[100005],b,sa,sb,sc;
int choce(int i,int j){
	int s=5;
	for(int f=1;f<=3;f++){
		if(f!=j and f!=a[i][4] and a[i][f]>a[i][s]){
			s=f;
		}
	}
	return s;
}
bool bj(int a1,int b1){
	if(a[a1][0]==b and a[b1][0]==b){
		return (a[a1][b]-a[a1][choce(a1,b)])<(a[b1][b]-a[b1][choce(b1,b)]);
	}else{
		if(a[a1][0]==b){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[i]=i;
			a[i][0]=choce(i,0);
//			cout<<a[i][0]<<'\n';
			if(i>1 and a[0][a[i][0]]==n/2){
				b=a[i][0];
				sort(s+1,s+i-1,bj);
//				cout<<s[1]<<" ! "<<i<<'<'<<b<<">\n";
				sa=choce(s[1],b);
				sb=choce(i,b);
				sc=(a[s[1]][b]-a[s[1]][sa])<=(a[i][b]-a[i][sb]);
//				cout<<a[s[1]][sa]+a[i][b]<<"<->"<<a[s[1]][b]+a[i][sb]<<"?="<<sc<<'\n';
				if(sc){
					a[0][b]--;
					a[s[1]][0]=sa;
					a[s[1]][4]=b;
					a[0][a[s[1]][0]]++;
				}else{
					a[i][0]=sb;
				}
			}
			a[0][a[i][0]]++;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][0]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
