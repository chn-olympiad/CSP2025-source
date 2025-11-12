#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int ans;
struct fp{
	int a,b,c;
}s[100005];
struct pd{
	bool a,b,c;
};
int nd[100005];
pd c[100005];
fp cnt;
int t;
int cc;
int cz;//差为0的数 
int reads(){
	char c;
	int k=0;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){//开始
	for(int i=1;i<=n;i++){
		s[i].a=0,s[i].b=0,s[i].c=0;
		nd[i]=0;
		c[i].a=0,c[i].b=0,c[i].c=0;
	} 
	cnt.a=0,cnt.b=0,cnt.c=0;
	cc=0,ans=0,cz=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		s[i].a=reads(),s[i].b=reads(),s[i].c=reads();	
	}
	for(int i=1;i<=n;i++){
		if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
			c[i].a=1;
			cnt.a++;
			ans+=s[i].a;
		}
		else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
			c[i].b=1;
			cnt.b++;
			ans+=s[i].b;
		}
		else{
			c[i].c=1;
			cnt.c++;
			ans+=s[i].c;
		}
	}
	if(cnt.a>n/2){
		cc=cnt.a-(n/2);
		for(int i=1;i<=n;i++){
			if(c[i].a){
				nd[i]=min(s[i].a-s[i].b,s[i].a-s[i].c);
				if(!nd[i])cz++;
			}
		}
	}
	else if(cnt.b>n/2){
		cc=cnt.b-(n/2);
		for(int i=1;i<=n;i++){
			if(c[i].b){
				nd[i]=min(s[i].b-s[i].a,s[i].b-s[i].c);
				if(!nd[i])cz++;
			}
		}
	}
	else{
		cc=cnt.c-(n/2);
		for(int i=1;i<=n;i++){
			if(c[i].c){
				nd[i]=min(s[i].c-s[i].a,s[i].c-s[i].b);
				if(!nd[i])cz++;
			}
		}
	}
	cc=cc-cz;
	sort(nd+1,nd+n+1);
	for(int i=1;i<=n;i++){
		if(nd[i]!=0){
			int k=i+cc;
			for(int j=i;j<k;j++){
				ans=ans-nd[j];
			}
			break;
		}
	}
	cout<<ans<<'\n';
	}
	return 0;
}
