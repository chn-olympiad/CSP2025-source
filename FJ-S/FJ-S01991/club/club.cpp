#include<bits/stdc++.h>
using namespace std;

int t,n,f=1;
struct d{
	int x,y,z;
}a[100001];
int b[100001];
int s[3];
int w[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sa=0,c;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[i]=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].y==0 && a[i].z==0 && f==1) f=1;
			else f=0;
		}
		if(f==1){
			sort(b+1,b+n+1);
			if(n%2==0) c=n/2;
			else if(n%2==1) c=n/2+1;
			for(int i=n;i>c;i--) sa+=b[i];
			cout<<sa<<endl;
		}else if(n==2){
			for(int i=1;i<=n;i++){
				if(b[i]==a[i].x){
					s[i]=1;
					w[i]=max(a[i].y,a[i].z);
				}else if(b[i]==a[i].y){
					s[i]=2;
					w[i]=max(a[i].x,a[i].z);
				}else if(b[i]==a[i].z){
					s[i]=3;
					w[i]=max(a[i].x,a[i].y);
				}
			}
			if(s[1]!=s[2]) cout<<b[1]+b[2];
			else if(s[1]==s[2]){
				int sum1,sum2;
				sum1=b[1]+w[2];
				sum2=b[2]+w[1];
				cout<<max(sum1,sum2);
			}
		}
	}
	return 0;
}
