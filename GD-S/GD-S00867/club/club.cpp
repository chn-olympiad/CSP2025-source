#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long sum=0;
struct st{
	int num1,b1,num2,b2;
	int c;int id;
}s[N];
bool cmp(st x,st y){
	return x.c>y.c;
}
int t,n,num[3],k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;num[0]=num[1]=num[2]=0;
		scanf("%d",&n);
		k=n/2;
		int p[3],ip[3];
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[0],&p[1],&p[2]);
			ip[0]=p[0];ip[1]=p[1];ip[2]=p[2];
			sort(p,p+3);
			if(p[2]==ip[0]) s[i].b1=0;
			else if(p[2]==ip[1]) s[i].b1=1;
			else if(p[2]==ip[2]) s[i].b1=2;
			if(p[1]==ip[0]&&s[i].b1!=0) s[i].b2=0;
			else if(p[1]==ip[1]&&s[i].b1!=1) s[i].b2=1;
			else if(p[1]==ip[2]&&s[i].b1!=2) s[i].b2=2;
			s[i].num1=p[2];
			s[i].num2=p[1];
			s[i].c=p[2]-p[1];
			s[i].id=i;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(num[s[i].b1]<k){
				sum+=s[i].num1;
				num[s[i].b1]++;
			}
			else{
				sum+=s[i].num2;
				num[s[i].b2]++;
			}
		}
		cout<<sum<<endl;
	}
}
