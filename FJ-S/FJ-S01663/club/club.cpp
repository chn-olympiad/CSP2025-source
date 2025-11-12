#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100010],b[100010],c[100010];
long long sum;
int a_1[100010],b_1[100010];
 
bool cmp(int x,int y){return x>y;}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		bool flag=false;
		for(int i=1;i<=n;i++)
			if(c[i]!=0) flag=true;
		if(!flag){
			int as=0,bs=0;
			for(int i=1;i<=n;i++)
				a_1[i]=a[i],b_1[i]=b[i];
			sort(a_1+1,a_1+n+1,cmp),sort(b_1+1,b_1+n+1,cmp);
			for(int i=1;i<=n;i++)
				if(as==n/2) bs++,sum+=b_1[i];
				else if(bs==n/2) as++,sum+=a_1[i];
				else
					if(a_1[i]>=b_1[i]) sum+=a_1[i],as++;
					else sum+=b_1[i],bs++;
			cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			sum+=max(a[i],max(b[i],c[i]));
		cout<<sum<<"\n";
	}
	return 0;
} 
