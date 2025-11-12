#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long m[500010];
struct p{
	int a;
	int b;
	int l;
}x[500010];
int u[500010];
int cnt=1;
int o;
int ans;
bool cmp(p f,p g){
	//if(f.l!=g.l)
	return f.l<g.l;
	//else if(f.a!=g.a) return f.a<g.a;
	//else return f.b<g.b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(m[i]==0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(m[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			long long sum=m[i];
			if(sum==k){
				x[cnt].a=i;
				x[cnt].b=i;
				x[cnt].l=(i-i)+1;
				cnt=cnt+1;				
			}
			for(int j=i+1;j<=n;j++){
				sum=sum^m[j];
				if(sum==k){
					x[cnt].a=i;
					x[cnt].b=j;
					x[cnt].l=(j-i)+1;
					cnt=cnt+1;
					//cout<<x[cnt].a<<" "<<x[cnt].b;
				}else{
					continue;
				}
			}
		}
		//cout<<cnt;
		cnt=cnt-1;
		sort(x+1,x+cnt+1,cmp);
		//for(int i=1;i<=cnt;i++){
			//cout<<x[i].a<<" "<<x[i].b<<endl;
		//}
		for(int i=1;i<=cnt;i++){
			bool flag=false;
			for(int j=x[i].a;j<=x[i].b;j++){
				if(u[j]==1){
					flag=true;
					break;
				}
			}
			if(flag==0){
				for(int j=x[i].a;j<=x[i].b;j++){
					u[j]=1;
				}
				ans++;
			}else if(flag==true){
				continue;
			}
		}
		cout<<ans;
	}

	return 0;
}