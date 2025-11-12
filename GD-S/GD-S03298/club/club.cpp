#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn],b[maxn],c[maxn];
bool a1[maxn],b1[maxn],c1[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c1,0,sizeof(c1));
		int n,sum=0,p1=0,p2=0,p3=0,l1,l2,l3;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i] && a[i]>c[i] && p1<(n/2)){
				a1[i]=true;
				sum+=a[i];
				p1++;
			}
			else if(b[i]>a[i] && b[i]>c[i] && p2<(n/2)){
				b1[i]=true;
				sum+=b[i];
				p2++;
			}
			else if(c[i]>a[i] && c[i]>b[i] && p3<(n/2)){
				c1[i]=true;
				sum+=c[i];
				p3++;
			}
			else if(a[i]>b[i] && a[i]>c[i] && p1>=(n/2)){
				for(int j=1;j<=n;j++){
					if(a1[j]==true){
						if(a[i]>a[j]){
							a1[j]=false;
							a1[i]=true;
							sum=sum-a[j]+a[i];
						}
						else continue;
					}
				}
			}
			else if(b[i]>a[i] && b[i]>c[i] && p2>=(n/2)){
				for(int j=1;j<=n;j++){
					if(b1[j]==true){
						if(b[i]>b[j]){
							b1[j]=false;
							b1[i]=true;
							sum=sum-b[j]+b[i];
						}
						else continue;
					}
				}
			}
			else if(c[i]>b[i] && c[i]>a[i] && p3>=(n/2)){
				for(int j=1;j<=n;j++){
					if(c1[j]==true){
						if(c[i]>c[j]){
							c1[j]=false;
							c1[i]=true;
							sum=sum-c[j]+c[i];
						}
						else continue;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
