#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,sum;
struct club{
	int a,b,c,m,p;
	bool ch;
}s[100001];
bool cmp(club x,club y){
	return x.m>y.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		x=y=z=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b && s[i].a>s[i].c){
				s[i].m=2*s[i].a-s[i].b-s[i].c;
				s[i].p=1;
			}else if(s[i].b>s[i].a && s[i].b>s[i].c){
				s[i].m=2*s[i].b-s[i].a-s[i].c;
				s[i].p=2;
			}else{
				s[i].m=2*s[i].c-s[i].a-s[i].b;
				s[i].p=3;
			}
			s[i].ch=true;
		}sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].a>s[i].b && s[i].a>s[i].c && s[i].ch && x){
				sum+=s[i].a;
				s[i].ch=false;
				x--;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].b>s[i].c && s[i].ch && y){
				sum+=s[i].b;
				s[i].ch=false;
				y--;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].ch && z){
				sum+=s[i].c;
				s[i].ch=false;
				z--;
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
