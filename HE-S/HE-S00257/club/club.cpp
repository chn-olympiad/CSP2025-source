#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int T,n;
struct re{
	int a,b,c;
	int ma1,ma2;
}x[N];
bool cmp(re a,re b){
	if(a.ma1==b.ma1) return a.ma2>b.ma2;
	return a.ma1>b.ma1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(x,0,sizeof(x));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].ma1=max(x[i].a,max(x[i].b,x[i].c));
			if(x[i].ma1==x[i].a) x[i].ma2=max(x[i].b,x[i].c);
			else if(x[i].ma1==x[i].b) x[i].ma2=max(x[i].a,x[i].c);
			else if(x[i].ma1==x[i].c) x[i].ma2=max(x[i].a,x[i].b);
		}
		sort(x+1,x+1+n,cmp);
		int sum1=0,sum2=0,sum3=0;
		int mi1,mi2,mi3;
		int ans=0,mi=0;
		char p;
		bool k=0;
		int num=n/2;
		for(int i=1;i<=n;i++){
			if(x[i].ma1==x[i].a&&x[i].ma1==x[i].b){
				if(sum1>sum2) sum2++;
				else sum1++;
				ans+=x[i].ma1;
			}else if(x[i].ma1==x[i].a&&x[i].ma1==x[i].c){
				if(sum1>sum3) sum3++;
				else sum1++;
				ans+=x[i].ma1;
			}else if(x[i].ma1==x[i].c&&x[i].ma1==x[i].b){
				if(sum3>sum2) sum2++;
				else sum3++;
				ans+=x[i].ma1;
			}else if(x[i].ma1==x[i].a&&sum1!=num){
				sum1++;
				mi1=i;
				ans+=x[i].ma1;
			}
			else if(x[i].ma1==x[i].b&&sum2!=num){
				sum2++;
				mi2=i;
				ans+=x[i].ma1;
			}
			else if(x[i].ma1==x[i].c&&sum3!=num){
				sum3++;
				mi3=i;
				ans+=x[i].ma1;
			}else{
				if(sum1==num&&!k) mi=mi1,k=1,p='a';
				else if(sum2==num&&!k) mi=mi2,k=1,p='b';
				else if(sum3==num&&!k) mi=mi3,k=1,p='c';
				if((p=='a'&&x[i].ma1!=x[i].a)||(p=='b'&&x[i].ma1!=x[i].b)||(p=='c'&&x[i].ma1!=x[i].c)) ans+=x[i].ma1;
				else if(x[i].ma1+x[mi].ma2>=x[i].ma2+x[mi].ma1){
						ans-=x[mi].ma1;
						ans+=x[i].ma1+x[mi].ma2;
						mi=i;
				}else ans+=x[i].ma2;
			}
		}
		cout<<ans<<endl;
	}
}
