#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[100001][4],c1,c2,c3,s1,s2,s3,b[1000001],c[1000001];
	cin>>t;
	while(t--){
		int c1=0,c2=0,c3=0,s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(b[i]==a[i][1]){
				c[i]=1;
				s1+=b[i];
				c1++;
			}else if(b[i]==a[i][2]){
				c[i]=2;
				s2+=b[i];
				c2++;
			}else {
				c[i]=3;
				s3+=b[i];
				c3++;
			}
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			cout<<s1+s2+s3<<endl;
			continue;
		}else{
			int q=c1,w=c2,e=c3;
			if(c1>n/2){
				for(int i=1;c1>n/2&&i<=q;i++){
					if(c[i]==1){
						s1-=b[i];
						c1--;
						if(a[i][2]>=a[i][3]){
							c[i]=2;
							s2+=a[i][2];
							c2++;
						}else{
							c[i]=3;
							s3+=a[i][3];
							c3++;
						}
					}
				}
			}
			if(c2>n/2){
				for(int i=1;c2>n/2&&i<=w;i++){
					if(c[i]==2){
						s1-=b[i];
						c1--;
						if(a[i][1]>=a[i][3]){
							c[i]=1;
							s1+=a[i][1];
							c1++;
						}else{
							c[i]=3;
							s3+=a[i][3];
							c3++;
						}
					}
				}
			}
			if(c3>n/2){
				for(int i=1;c3>n/2&&i<=e;i++){
					if(c[i]==1){
						s1-=b[i];
						c1--;
						if(a[i][2]>=a[i][1]){
							c[i]=2;
							s2+=a[i][2];
							c2++;
						}else{
							c[i]=1;
							s1+=a[i][1];
							c1++;
						}
					}
				}
			}
		}
		cout<<s1+s2+s3<<endl;
	}
	return 0;
}
