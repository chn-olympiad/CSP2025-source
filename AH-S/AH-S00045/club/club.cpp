#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e+7;
bool cmp(int s1,int s2){
	return s1<s2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100010][3],b[100010],x1=0,x2=0,x3=0,ans=0,c[100010];
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				x1++;
				b[i]=a[i][1]-a[i][2];
				c[i]=1;
			}else if(a[i][1]>=a[i][2]&&a[i][3]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				x1++;
				b[i]=a[i][1]-a[i][3];
				c[i]=1;
			}else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				x2++;
				b[i]=a[i][2]-a[i][1];
				c[i]=2;
			}else if(a[i][1]>=a[i][2]&&a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				ans+=a[i][3];
				x3++;
				b[i]=a[i][3]-a[i][1];
				c[i]=3;
			}else if(a[i][3]>=a[i][1]&&a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]){
				ans+=a[i][2];
				x2++;
				b[i]=a[i][2]-a[i][3];
				c[i]=2;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]&&a[i][2]>= a[i][1]){
				ans+=a[i][3];
				x3++;
				b[i]=a[i][3]-a[i][2];
				c[i]=3;
			}
		}
		if(x1<=(n/2)&&x2<=(n/2)&&x3<=(n/2)){
			cout<<ans;
			continue;
		}else{
			int q1=max(x2,x3);
			int q=max(x1,q1);
			int w=q-(n/2);
			if(x1>(n/2)){
				for(int i=1;i<=n;i++){
					if(c[i]!=1){
						b[i]=N;
					}
				}
			}
			if(x2>(n/2)){
				for(int i=1;i<=n;i++){
					if(c[i]!=2){
						b[i]=N;
					}
				}
			}
			if(x3>(n/2)){
				for(int i=1;i<=n;i++){
					if(c[i]!=3){
						b[i]=N;
					}
				}
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=w;i++){
				ans-=b[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
