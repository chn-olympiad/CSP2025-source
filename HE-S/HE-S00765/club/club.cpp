#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a1,a2,a3,b1,b2,b3,b4,b5,b6;
}a[100005],b[100005];
bool cmp(node a,node b){
	return a.b1>b.b1;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		long long sum=0;
		int n;cin>>n;
		int clu[4]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				b[i].b1=a[i].a1;
				b[i].b2=1;
				if(a[i].a2>a[i].a3){
					b[i].b3=a[i].a2;
					b[i].b4=2;
				}
				else{
					b[i].b5=a[i].a3;
					b[i].b6=3;
				}
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				b[i].b1=a[i].a2;
				b[i].b2=2;
				if(a[i].a1>a[i].a3){
					b[i].b3=a[i].a1;
					b[i].b4=1;
				}
				else{
					b[i].b5=a[i].a3;
					b[i].b6=3;
				}
			}
			else{
				b[i].b1=a[i].a3;
				b[i].b2=3;
				if(a[i].a1>a[i].a2){
					b[i].b3=a[i].a1;
					b[i].b4=1;
				}
				else{
					b[i].b5=a[i].a2;
					b[i].b6=2;
				}
			}
		}
		sort(b+1,b+1+n,cmp);
		if(n==2){
			if(b[1].b2!=b[2].b2){
				cout<<b[1].b1+b[2].b1<<"\n";
			}
			else{
				if(b[1].b1+b[2].b3>b[1].b3+b[2].b1){
					cout<<b[1].b1+b[2].b3<<"\n";
				}
				else{
					cout<<b[1].b3+b[2].b1<<"\n";
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(clu[b[i].b2]<(n/2)){
				clu[b[i].b2]++;
				sum+=b[i].b1;
			}
			else{
				if(clu[b[i].b4]<(n/2)){
					clu[b[i].b4]++;
					sum+=b[i].b3;
				}
				else{
					clu[b[i].b6]++;
					sum+=b[i].b5;
				}
			}
		}
		cout<<sum<<"\n";	
	}
	return 0;
}
