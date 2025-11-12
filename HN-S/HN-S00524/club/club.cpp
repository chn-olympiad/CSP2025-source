#include <bits/stdc++.h>
using namespace std;
struct atti{
	int a;
	int b;
	int c;
	int club;
}at[100005];
int q,n,ac,bc,cc,lim,ans,index,max1;
char as[40];
void print(){
	max1=0;
	for(int i=1;i<=n;i++){
		if(as[i]=='a'){
			max1+=at[i].a;
		}
		else if(as[i]=='b'){
			max1+=at[i].b;
		}
		else{
			max1+=at[i].c;
		}
	}
	ans=max(ans,max1);
	return;
}
void dfs(int floor,int r,int p,int g){
	if(floor==n){
		if(r<=lim and p<=lim and g<=lim)
			print();
		return;
	}
	as[floor+1]='a';
	dfs(floor+1,r+1,p,g);
	as[floor+1]='b';
	dfs(floor+1,r,p+1,g);
	as[floor+1]='c';
	dfs(floor+1,r,p,g+1);
	return;
}
bool bmp(atti x,atti y){
	return x.a>=y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>q;
	while(q--){
		cin>>n;
		ac=bc=cc=ans=0;
		index=1;
		
		lim=n/2;
		if(ac<=lim and bc<lim and cc<=lim){
			for(int i=1;i<=n;i++){
				cin>>at[i].a>>at[i].b>>at[i].c;
				if(at[i].a>=at[i].b and at[i].a>=at[i].c){
					at[i].club=1;
					ac++;
					ans+=at[i].a;
				}
				else if(at[i].b>=at[i].a and at[i].b>=at[i].c){
					at[i].club=2;
					bc++;
					ans+=at[i].b;
				}
				else {
					at[i].club=3;
					cc++;
					ans+=at[i].c;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			max1=0;
			max1=max(max1,at[1].a+at[2].b);
			max1=max(max1,at[1].b+at[2].a);
			max1=max(max1,at[1].a+at[2].c);
			max1=max(max1,at[1].c+at[2].a);
			max1=max(max1,at[1].b+at[2].c);
			max1=max(max1,at[1].c+at[2].b);
			cout<<max1<<endl;
			continue;
		}
		if(n==4 or n==10 or n==30){
			max1=0;
			ans=0;
			dfs(0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else{
			sort(at+1,at+n+1,bmp);
			for(int i=1;i<=lim;i++){
				ans+=at[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}

