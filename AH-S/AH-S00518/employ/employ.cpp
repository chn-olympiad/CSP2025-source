#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>

#define LL long long

using namespace std;

const int N=500+10;

int n,m,cnt=0;
string s;
int a[N],p[N];
bool vis[N];

bool Check(){
	
	int tot=0;
	for(int i=1;i<=n;i++){
		if(tot>=a[p[i]]){
			tot++;
			continue;
		}
		if(s[i]=='0')
			tot++;
	}
	return n-tot>=m;
	
}

void DFS(int x){
	
	if(x==n+1){
		if(Check())
			cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			DFS(x+1);
			vis[i]=false;
		}
	
}

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    scanf("%d%d",&n,&m);
    cin>>s;
    s="1"+s;
    bool ok=false;
    for(int i=1;i<=n;i++)
		if(s[i]=='0'){
			ok=true;
			break;
		}
	if(!ok){
		LL ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*1LL*i)%998244353;
		}
		printf("%lld\n",ans);
		return 0;
	}
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	DFS(1);
	printf("%d\n",cnt);
    return 0;

    fclose(stdin);
    fclose(stdout);

}
