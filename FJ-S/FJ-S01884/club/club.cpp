#include<bits/stdc++.h>
using namespace std;
struct q{
	int a;
	int b;
	int c;
}cu[10005];
int man,ma,n;
void dfs(int k,int a,int b,int c,int sum){
	if(a>ma||b>ma||c>ma){
		return ;
	}
	if(k==n+1){
		man=max(man,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(k+1,a+1,b,c,sum+cu[k].a);
		}
		else if(i==2){
			dfs(k+1,a,b+1,c,sum+cu[k].b);
		}
		else if(i==3){
			dfs(k+1,a,b,c+1,sum+cu[k].c);
		}
	}
	return;
}
int cmp(q a,q b){
	if(max(a.a,a.b)!=max(b.a,b.b))
	return max(a.a,a.b)>max(b.a,b.b);
	else
	return min(a.a,a.b)>min(b.a,b.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ma=n/2;
		for(int i=1;i<=n;i++){
			cin>>cu[i].a>>cu[i].b>>cu[i].c;
		}
		if(n<=200){
		dfs(1,0,0,0,0);
		cout<<man;
		man=-1;
		}
		else{
			ma=n/2;
			int l=0,r=0,sum=0,i=1;
			while(i<=n){
				if((l<=ma&&cu[i].a>cu[i].b)||r>ma){
					l++;
					sum+=cu[i].a;
				}
				else if((r<=ma&&cu[i].b>cu[i].a)||l>ma){
					r++;
					sum+=cu[i].b;
				}
				i++;
			}
			cout<<sum;
		}
	}
}
