#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int a,b,c;
	int f,s,t;
	void input(){
		cin>>a>>b>>c;
	}
}mem[N];
bool cmp1(node x,node y){return x.a>y.a;}
bool cmp2(node x,node y){return x.b>y.b;}
bool cmp3(node x,node y){return x.c>y.c;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0,cnt1=INT_MIN,cnt2=INT_MIN,cnt3=INT_MIN,e=0;
		cin>>n;
		for(int i=1;i<=n;i++) mem[i].input();
		if(mem[1].a!=0&&mem[1].b==0&&mem[1].c==0){
			int sum=0;
			sort(mem+1,mem+1+n,cmp1);
			for(int i=1;i<=n/2;i++) sum+=mem[i].a;
			cout<<sum;
		}
		else{
		
		for(int i=1;i<=n/2;i++){
			e+=mem[i].a;
			for(int j=i+1;j<=n;j++){
				if(mem[j].b>mem[j].c) cnt+=mem[j].b;
				else cnt+=mem[j].c;
			}
			cnt1=max(cnt1,e+cnt);
			cnt=0;
		}
		cnt=0; e=0;
		sort(mem+1,mem+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			e+=mem[i].b;
			for(int j=i+1;j<=n;j++){
				if(mem[j].a>mem[j].c) cnt+=mem[j].a;
				else cnt+=mem[j].c;
			}
			cnt2=max(cnt2,e+cnt);
			cnt=0;
		}
		cnt=0; e=0;
		sort(mem+1,mem+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			e+=mem[i].c;
			for(int j=i+1;j<=n;j++){
				if(mem[j].a>mem[j].b) cnt+=mem[j].a;
				else cnt+=mem[j].b;
			}
			cnt3=max(cnt3,e+cnt);
			cnt=0;
		}
		cout<<max(cnt1,max(cnt2,cnt3))<<"\n";
		}
	}
	return 0;
}
