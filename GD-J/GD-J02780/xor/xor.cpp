#include<bits/stdc++.h>
using namespace std;
struct w{
	int s,f;
};
w a[500005];
int n=0,k=0,ans=0,b=0;
bool fl=0;
void dfs(int j,int i,int b){
	if(i==j){
		fl=1;
		return ;
	}
	if(b^a[i-1].s<k){
		b=b^a[i-1].s;
		a[i-1].f=1;
		dfs(j,i-1,b);
		if(fl!=0)
		   a[i-1].f=0;
	}
	if(b^a[i-1].s ==k){
		b=b^a[i-1].s;
		fl=0;
		b=0;
		ans++;
		return ;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].s);
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i].s==k){
			ans++;
			j=i+1;
			a[i].f=1;
		}
		else if(i>j){
			b=a[i].s;
			dfs(j,i,b);
			if(fl!=0)
			  fl=0;
			else {
				j=i+1;
				a[i].f=1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
