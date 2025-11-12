#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long ans;
long long club[4];
struct stu{
	int a,b,c;
	int minl;
	int ch;
}s[100001];
bool cmp(stu x,stu y){
	return x.minl<y.minl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		ans=0;
		club[1]=0;
		club[2]=0;
		club[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int maxn=max(s[i].a,max(s[i].b,s[i].c));
			if(maxn==s[i].a){
				club[1]++;
				s[i].minl=maxn-max(s[i].b,s[i].c);
				s[i].ch=1;
			}else if(maxn==s[i].b){
				club[2]++;
				s[i].minl=maxn-max(s[i].a,s[i].c);
				s[i].ch=2;
			}else if(maxn==s[i].c){
				club[3]++;
				s[i].minl=maxn-max(s[i].b,s[i].a);
				s[i].ch=3;
			}
			ans+=maxn;
		}
		int prep=0;
		if(club[1]>(n/2)){
			for(int i=1;i<=n;i++){
				if(s[i].ch!=1) s[i].minl=20001;
			}
			prep=club[1]-(n/2);
			sort(s+1,s+n+1,cmp);
		}else if(club[2]>(n/2)){
			for(int i=1;i<=n;i++){
				if(s[i].ch!=2) s[i].minl=20001;
			}
			prep=club[2]-(n/2);
			sort(s+1,s+n+1,cmp);
		}else if(club[3]>(n/2)){
			for(int i=1;i<=n;i++){
				if(s[i].ch!=3) s[i].minl=20001;
			}
			prep=club[3]-(n/2);
			sort(s+1,s+n+1,cmp);
		}
		for(int i=1;i<=prep;i++){
			ans-=s[i].minl;
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
} 
