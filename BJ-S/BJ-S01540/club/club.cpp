#include<bits/stdc++.h>
using namespace std;
struct no{
	long long c,ii;
}x[100001],y[100001],z[100001];
bool cmp(no a,no b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n,num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].c>>y[i].c>>z[i].c;
			x[i].ii=i;
			y[i].ii=i;
			z[i].ii=i;
		}
		sort(x+1,x+n+1,cmp);
		sort(y+1,y+n+1,cmp);
		sort(z+1,z+n+1,cmp);
		if(n==2){
			num=max(x[1].c,max(x[2].c,max(y[1].c,max(y[2].c,max(z[1].c,max(z[2].c,max(x[1].c+y[2].c,max(x[1].c+y[2].c,max(y[1].c+z[2].c,y[1].c+x[2].c)))))))));
			cout<<num<<endl;
			continue;
		}
		if(n%3==0){
			for(int i=1;i<=n/3;i++){
				num+=x[i].c+y[i].c+z[i].c;
			}
		}else if(n%3==1){
			for(int i=1;i<=n/3;i++){
				num+=x[i].c+y[i].c+z[i].c;
			}
			num+=max(x[n/3+1].c,max(y[n/3+1].c,z[n/3+1].c));
		}else if(n%3==2){
			for(int i=1;i<=n/3+1;i++){
				num+=x[i].c+y[i].c+z[i].c;
			}
			num-=min(x[n/3+1].c,min(y[n/3+1].c,z[n/3+1].c));
		}
		cout<<num<<endl;
	}
	return 0;
}
