#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
struct node{
	int fi,se,th;
	int fin,sen,thn;
}p[100010];
struct node1{
	int type,num;
}tmp[5];
bool cmp1(node1 x,node1 y){
	return x.num>y.num;
}
bool cmp(node x,node y){
	if(x.fi==y.fi){
		if(x.se==y.se){
			return x.th>y.th;
		}
		return x.se>y.se;
	}
	return x.fi>y.fi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll ans=0,pa=0,pb=0,pc=0;
		cin>>n;
		pa=pb=pc=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			tmp[1].num=a;tmp[2].num=b;tmp[3].num=c;
			tmp[1].type=1;tmp[2].type=2;tmp[3].type=3;
			sort(tmp+1,tmp+4,cmp1);
			p[i].fi=tmp[1].num;p[i].se=tmp[2].num;p[i].th=tmp[3].num;
			p[i].fin=tmp[1].type;p[i].sen=tmp[2].type;p[i].thn=tmp[3].type;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(p[i].fin==1&&pa>0){
				pa--;
				ans+=p[i].fi;
			}
			else if(p[i].fin==2&&pb>0){
				pb--;
				ans+=p[i].fi;
			}
			else if(p[i].fin==3&&pc>0){
				pc--;
				ans+=p[i].fi;
			}
			else if(p[i].sen==1&&pa>0){
				pa--;
				ans+=p[i].se;
			}
			else if(p[i].sen==2&&pb>0){
				pb--;
				ans+=p[i].se;
			}
			else if(p[i].sen==3&&pc>0){
				pc--;
				ans+=p[i].se;
			}
			else if(p[i].thn==1&&pa>0){
				pa--;
				ans+=p[i].th;
			}
			else if(p[i].thn==2&&pb>0){
				pb--;
				ans+=p[i].th;
			}
			else{
				pc--;
				ans+=p[i].th;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
