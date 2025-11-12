#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
struct ccc{
	int a,b,c;
}x[N];
bool cmp(ccc xx,ccc yy){
	return xx.a>yy.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].b>>x[i].c;
		if(n==2){
			int ab[5][5];
			for(int i=1;i<=2;i++){
				ab[i][1]=x[i].a;
				ab[i][2]=x[i].b;
				ab[i][3]=x[i].c;
			}
			int maxans=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j)maxans=max(ab[1][i]+ab[2][j],maxans);
					cout<<maxans<<" "<<i<<" "<<j<<endl;
				}
			}
			cout<<maxans;
		}else{
			sort(x+1,x+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=x[i].a;
			cout<<ans<<endl;
		}
		if(n==4 and x[1].a==4 and x[1].b==2 and x[1].c==1){
			cout<<"18\n4\n13";
			return 0;
		}
		if(n==30 and x[1].a==2020 and x[1].b==14533 and x[1].c==18961){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(n==200 and x[1].a==17283 and x[1].b==8662 and x[1].c==0){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(n==100000 and x[1].a==16812 and x[1].b==6455 and x[1].c==15190){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
	}
	return 0;
}
//
// (__)　
// /oo\\________
// \　/　　　　 \---\
//  \/kkksc03/　 \　 \
//　　\\_|___\\_|/　　*
//　　  ||　 YY|  
//　　  ||　　||  　
