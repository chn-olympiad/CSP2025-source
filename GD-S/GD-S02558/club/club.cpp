#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
struct member{
	int a;
	int b;
	int c;
	int dis_max;
	int da;
	int db;
	int dc;
	int dmax;
	int dmin1;
	int dmin2;
	int dmin3;
}m[100010];
int mema;
int memb;
int memc;
int tp1[100010];
int ch[50];
struct tp{
	int a;
	int b;
	int dis_max;
	int da;
	int db;
	int dmin1;
	int dmin2;
}tp2[100010];
int check1(){
	for(int i=1;i<=n;i++){
		if(m[i].b!=0){
			return 0;
		}
		if(m[i].c!=0){
			return 0;
		}
	}
	return 1;
}
int check2(){
	for(int i=1;i<=n;i++){
		if(m[i].c!=0){
			return 0;
		}
	}
	return 1;
}
int dfs(int step){
	if(step>n){
		int s=0;
		for(int i=1;i<=n;i++){
			if(ch[i]==1){
				s+=m[i].a;
			}
			else if(ch[i]==2){
				s+=m[i].b;
			}
			else{
				s+=m[i].c;
			}
		}
		ans=max(ans,s);
		return 0;
	}
	if(mema<n/2){
		mema++;
		ch[step]=1;
		dfs(step+1);
		mema--;
	}
	if(memb<n/2){
		memb++;
		ch[step]=2;
		dfs(step+1);
		memb--;
	}
	if(memc<n/2){
		memc++;
		ch[step]=3;
		dfs(step+1);
		memc--;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		mema=0;
		memb=0;
		memc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a;
			cin>>m[i].b;
			cin>>m[i].c;
			tp1[i]=m[i].a;
			tp2[i].a=m[i].a;
			tp2[i].b=m[i].b;
		}
		if(n==2){
			int ca1=m[1].a+m[2].b;
			int ca2=m[1].b+m[2].a;
			int ca3=m[1].a+m[2].c;
			int ca4=m[1].c+m[2].a;
			int ca5=m[1].b+m[2].c;
			int ca6=m[1].c+m[2].b;
			ans=max(ans,ca1);
			ans=max(ans,ca2);
			ans=max(ans,ca3);
			ans=max(ans,ca4);
			ans=max(ans,ca5);
			ans=max(ans,ca6);
			cout<<ans<<endl;
		}
		else if(n==4){
			int ca1=m[1].a+m[2].a+m[3].b+m[4].b;
			int ca2=m[1].a+m[2].b+m[3].b+m[4].a;
			int ca3=m[1].b+m[2].b+m[3].a+m[4].a;
			int ca4=m[1].b+m[2].a+m[3].b+m[4].a;
			int ca5=m[1].a+m[2].b+m[3].a+m[4].b;
			int ca6=m[1].a+m[2].a+m[3].c+m[4].c;
			int ca7=m[1].a+m[2].c+m[3].c+m[4].a;
			int ca8=m[1].c+m[2].c+m[3].a+m[4].a;
			int ca9=m[1].c+m[2].a+m[3].b+m[4].c;
			int ca10=m[1].a+m[2].c+m[3].a+m[4].c;
			int ca11=m[1].c+m[2].c+m[3].b+m[4].b;
			int ca12=m[1].c+m[2].b+m[3].b+m[4].c;
			int ca13=m[1].b+m[2].b+m[3].c+m[4].c;
			int ca14=m[1].b+m[2].c+m[3].b+m[4].c;
			int ca15=m[1].c+m[2].b+m[3].c+m[4].b;
			int ca16=m[1].a+m[2].a+m[3].b+m[4].c;
			int ca17=m[1].a+m[2].a+m[3].c+m[4].b;
			int ca18=m[1].a+m[2].b+m[3].a+m[4].c;
			int ca19=m[1].a+m[2].c+m[3].a+m[4].b;
			int ca20=m[1].a+m[2].b+m[3].c+m[4].a;
			int ca21=m[1].a+m[2].c+m[3].b+m[4].a;
			int ca22=m[1].b+m[2].a+m[3].c+m[4].a;
			int ca23=m[1].c+m[2].a+m[3].b+m[4].a;
			int ca24=m[1].b+m[2].c+m[3].a+m[4].a;
			int ca25=m[1].c+m[2].b+m[3].a+m[4].a;
			int ca26=m[1].b+m[2].b+m[3].a+m[4].c;
			int ca27=m[1].b+m[2].b+m[3].c+m[4].a;
			int ca28=m[1].b+m[2].a+m[3].b+m[4].c;
			int ca29=m[1].b+m[2].c+m[3].b+m[4].a;
			int ca30=m[1].b+m[2].a+m[3].c+m[4].b;
			int ca31=m[1].b+m[2].c+m[3].a+m[4].b;
			int ca32=m[1].a+m[2].b+m[3].c+m[4].b;
			int ca33=m[1].c+m[2].b+m[3].a+m[4].b;
			int ca34=m[1].a+m[2].c+m[3].b+m[4].b;
			int ca35=m[1].c+m[2].a+m[3].b+m[4].b;
			int ca36=m[1].c+m[2].c+m[3].b+m[4].a;
			int ca37=m[1].c+m[2].c+m[3].a+m[4].b;
			int ca38=m[1].c+m[2].b+m[3].c+m[4].a;
			int ca39=m[1].c+m[2].a+m[3].c+m[4].b;
			int ca40=m[1].c+m[2].b+m[3].a+m[4].c;
			int ca41=m[1].c+m[2].a+m[3].b+m[4].c;
			int ca42=m[1].b+m[2].c+m[3].a+m[4].c;
			int ca43=m[1].c+m[2].c+m[3].b+m[4].c;
			int ca44=m[1].b+m[2].a+m[3].c+m[4].c;
			int ca45=m[1].c+m[2].b+m[3].c+m[4].c;
			ans=max(ans,ca1);
			ans=max(ans,ca2);
			ans=max(ans,ca3);
			ans=max(ans,ca4);
			ans=max(ans,ca5);
			ans=max(ans,ca6);
			ans=max(ans,ca7);
			ans=max(ans,ca8);
			ans=max(ans,ca9);
			ans=max(ans,ca10);
			ans=max(ans,ca11);
			ans=max(ans,ca12);
			ans=max(ans,ca13);
			ans=max(ans,ca14);
			ans=max(ans,ca15);
			ans=max(ans,ca16);
			ans=max(ans,ca17);
			ans=max(ans,ca18);
			ans=max(ans,ca19);
			ans=max(ans,ca20);
			ans=max(ans,ca21);
			ans=max(ans,ca22);
			ans=max(ans,ca23);
			ans=max(ans,ca24);
			ans=max(ans,ca25);
			ans=max(ans,ca26);
			ans=max(ans,ca27);
			ans=max(ans,ca28);
			ans=max(ans,ca29);
			ans=max(ans,ca30);
			ans=max(ans,ca31);
			ans=max(ans,ca32);
			ans=max(ans,ca33);
			ans=max(ans,ca34);
			ans=max(ans,ca35);
			ans=max(ans,ca36);
			ans=max(ans,ca37);
			ans=max(ans,ca38);
			ans=max(ans,ca39);
			ans=max(ans,ca40);
			ans=max(ans,ca41);
			ans=max(ans,ca42);
			ans=max(ans,ca43);
			ans=max(ans,ca44);
			ans=max(ans,ca45);
			cout<<ans<<endl;
		}
		else if(check1()==1){
			sort(tp1+1,tp1+n+1);
			for(int j=n;j>=n/2+1;j--){
				ans+=tp1[j];
			}
			cout<<ans<<endl;
		}
		else if(check2()==1){
			for(int i=1;i<=n;i++){
				if(tp2[i].a>=tp2[i].b){
					tp2[i].dis_max=1;
					tp2[i].da=m[i].a-tp2[i].a;
					tp2[i].db=m[i].b-tp2[i].a;
					tp2[i].dmin1=tp2[i].db;
					tp2[i].dmin2=tp2[i].da;
				}
				else{
					tp2[i].dis_max=2;
					tp2[i].da=m[i].a-tp2[i].b;
					tp2[i].db=m[i].b-tp2[i].b;
					tp2[i].dmin1=tp2[i].da;
					tp2[i].dmin2=tp2[i].db;
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(tp2[i].dmin2>tp2[j].dmin2){
						swap(tp2[i],tp2[j]);
					}
					else if(tp2[i].dmin2==tp2[j].dmin2){
						if(tp2[i].dmin1>tp2[j].dmin1){
							swap(tp2[i],tp2[j]);
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(tp2[i].dis_max==1){
					if(mema<n/2){
						ans+=tp2[i].a;
						mema++;
					}
					else{
						ans+=tp2[i].b;
						memb++;
					}
				}
				else {
					if(memb<n/2){
						ans+=tp2[i].b;
						memb++;
					}
					else{
						ans+=tp2[i].a;
						mema++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(n<=20){
			dfs(1);
			cout<<ans<<endl;
		} 
		else{
			for(int i=1;i<=n;i++){
				if(m[i].a>=m[i].b&&m[i].a>=m[i].c){
					m[i].dis_max=1;
					m[i].dmax=m[i].a;
					m[i].dmin3=m[i].a;
					m[i].da=m[i].a-m[i].dmax;
					m[i].db=m[i].b-m[i].dmax;
					m[i].dc=m[i].c-m[i].dmax;
					if(m[i].db>=m[i].dc){
						m[i].dmin2=m[i].db;
						m[i].dmin3=m[i].dc;
					}
					else{
						m[i].dmin2=m[i].dc;
						m[i].dmin3=m[i].db;
					}
				}
				else if(m[i].b>=m[i].a&&m[i].b>=m[i].c){
					m[i].dis_max=2;
					m[i].dmax=m[i].b;
					m[i].dmin3=m[i].b;
					m[i].da=m[i].a-m[i].dmax;
					m[i].db=m[i].b-m[i].dmax;
					m[i].dc=m[i].c-m[i].dmax;
					if(m[i].da>=m[i].dc){
						m[i].dmin2=m[i].da;
						m[i].dmin3=m[i].dc;
					}
					else{
						m[i].dmin2=m[i].dc;
						m[i].dmin3=m[i].da;
					}
				}
				else{
					m[i].dis_max=3;
					m[i].dmax=m[i].c;
					m[i].dmin3=m[i].c;
					m[i].da=m[i].a-m[i].dmax;
					m[i].db=m[i].b-m[i].dmax;
					m[i].dc=m[i].c-m[i].dmax;
					if(m[i].da>=m[i].db){
						m[i].dmin2=m[i].da;
						m[i].dmin3=m[i].db;
					}
					else{
						m[i].dmin2=m[i].db;
						m[i].dmin3=m[i].da;
					}
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(m[i].dmin3>m[j].dmin3){
						swap(m[i],m[j]);
					}
					else if(m[i].dmin3==m[j].dmin3){
						if(m[i].dmin2>m[j].dmin2){
							swap(m[i],m[j]);
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(m[i].dis_max==1){
					if(mema<n/2){
						ans+=m[i].a;
						mema++;
					}
					else{
						if(m[i].db<=m[i].dc&&memb<n/2){
							ans+=m[i].b;
							memb++;
						}
						else{
							ans+=m[i].c;
							memc++;
						}
					}
				}
				else if(m[i].dis_max==2){
					if(memb<n/2){
						ans+=m[i].b;
						memb++;
					}
					else{
						if(m[i].da<=m[i].dc&&mema<n/2){
							ans+=m[i].a;
							mema++;
						}
						else{
							ans+=m[i].c;
							memc++;
						}
					}
				}
				else{
					if(memc<n/2){
						ans+=m[i].c;
						memc++;
					}
					else{
						if(m[i].da<=m[i].db&&mema<n/2){
							ans+=m[i].a;
							mema++;
						}
						else{
							ans+=m[i].b;
							memb++;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
