#include<bits/stdc++.h>
using namespace std;
long long t;
struct node{
	long long a,b,c;
}s[100005];
bool cmp(node x,node y){
	return x.a<y.a;
}
long long ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,sum=0,a1=0,a2=0,a3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
				cin>>s[i].a>>s[i].b>>s[i].c;
				a1+=s[i].a;
				a2+=s[i].b;
				a3+=s[i].c;
		}
		if(a2==0&&a3==0){
			sort(s+1,s+n+1,cmp);
			for(int i=n;i>n/2;i--){
				sum+=s[i].a;
			}
			cout<<sum<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				ans[i]=1;
			}
			while(ans[n]<4){
				long long b1=0,b2=0,b3=0,c1=0,c2=0,c3=0;
				ans[1]++;
				if(ans[1]>3){
					int e=1;
					while(ans[e]>3&&e!=n){
						ans[e+1]+=ans[e]/3;
						ans[e]=1;
						e++;
					}
				}
				for(int i=1;i<=n;i++){
					if(ans[i]==1){
						b1++;
						c1+=s[i].a;
					}
					else if(ans[i]==2){
						b2++;
						c2+=s[i].b;
					}
					else if(ans[i]==3){
						b3++;
						c3+=s[i].c;
					}
				}
				if(b1<=n/2&&b2<=n/2&&b3<=n/2){
					sum=max(sum,c1+c2+c3);
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
