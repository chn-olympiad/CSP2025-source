#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}x[100007];
int a,b,c;
bool cmpa(Node a,Node b){
	return a.a-max(a.b,a.c)<b.a-max(b.b,b.c);
}
bool cmpb(Node a,Node b){
	return a.b-max(a.a,a.c)<b.b-max(b.a,b.c);
}
bool cmpc(Node a,Node b){
	return a.c-max(a.a,a.b)<b.c-max(b.a,b.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		a=b=c=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			ans+=max(x[i].a,max(x[i].b,x[i].c));
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)a++;
			else if(x[i].b>=x[i].c)b++;
			else c++;
		}
		if(a>n/2){
			ans=0;
			sort(x+1,x+n+1,cmpa);
			for(int i=1;i<=n/2;i++){
				ans+=max(x[i].b,x[i].c);
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=x[i].a;
			}
		}
		else if(b>n/2){
			ans=0;
			sort(x+1,x+n+1,cmpb);
			for(int i=1;i<=n/2;i++){
				ans+=max(x[i].a,x[i].c);
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=x[i].b;
			}
		}
		else if(c>n/2){
			ans=0;
			sort(x+1,x+n+1,cmpc);
			for(int i=1;i<=n/2;i++){
				ans+=max(x[i].a,x[i].b);
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=x[i].c;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	//system("fc club.out ans.out");
	return 0;
}
