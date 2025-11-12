#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,b,c;
}s[100005];
int t,n,a,b,c,sum,ma;
void dfs(int i){
	if(i>n){
		ma=max(sum,ma);
		return ;
	}
	if(a<n/2){
		a++;
		sum+=s[i].a;
		//cout<<endl<<a<<' '<<b<<' '<<c<<" s:"<<sum<<endl;
		dfs(i+1);
		a--;
		sum-=s[i].a;
	}
	if(b<n/2){
		b++;
		sum+=s[i].b;
		//cout<<endl<<a<<' '<<b<<' '<<c<<" s:"<<sum<<endl;
		dfs(i+1);
		b--;
		sum-=s[i].b;
	}
	if(c<n/2){
		c++;
		sum+=s[i].c;
		//cout<<endl<<a<<' '<<b<<' '<<c<<" s:"<<sum<<endl;
		dfs(i+1);
		c--;
		sum-=s[i].c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		a=0;b=0;c=0,sum=0,ma=-1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		dfs(1);
		cout<<ma<<endl;
	}
	return 0;
}
