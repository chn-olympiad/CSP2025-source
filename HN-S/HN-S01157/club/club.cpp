#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int t,q3[5],q4[N];
struct q{
	int a,b,c;
}w[N];
int c(q z,q x){
	return z.a>x.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0,cnt;
		cin>>n;
		cnt=n;
		memset(q4,0,sizeof(q4));
		int q1=n/2;
		for(int i=1;i<=3;i++){
			q3[i]=0;
		}
		for(int i=1;i<=n*3;i++){
			cin>>w[i].a;
			int q2=i%3,q5=i/3;
			if(!q2)q2=3;
			if(i%3!=0)q5++;
			w[i].b=q2;
			w[i].c=q5;
			
		}
		stable_sort(w+1,w+1+n*3,c);
		for(int i=1;i<=n*3;i++){
			if(!cnt)break;
			if(q3[w[i].b]+1>q1||q4[w[i].c])continue;
			ans+=w[i].a;
			q3[w[i].b]++;
			q4[w[i].c]=1;
			cnt--;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
