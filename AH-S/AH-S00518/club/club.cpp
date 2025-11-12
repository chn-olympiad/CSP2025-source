#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>

#define LL long long

using namespace std;

const int N=1e5+10;

int T;
int n;
int opt[N],cnt[N];
int t[N];

struct Node{
	
	int a,b,c;
	
	int Max(){
		
		return max(a,max(b,c));
		
	}
	
	int Opt(){
		
		int mx=Max();
		if(mx==a)
			return 1;
		if(mx==b)
			return 2;
		if(mx==c)
			return 3;
		
	}
	
	int Mid(){
		
		if(a<=max(b,c)&&a>=min(b,c))
			return a;
		if(b<=max(a,c)&&a>=min(a,c))
			return b;
		if(c<=max(a,b)&&a>=min(a,b))
			return c;
		
	}
	
}a[N];

void Solve(){

	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		opt[i]=a[i].Opt();
		cnt[opt[i]]++;
		ans+=a[i].Max();
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		printf("%d\n",ans);
		return ;
	}
	int tmp=1;
	if(cnt[1]>n/2)
		tmp=1;
	else if(cnt[2]>n/2)
		tmp=2;
	else
		tmp=3;
	int tot=0;
	for(int i=1;i<=n;i++)
		if(opt[i]==tmp)
			t[++tot]=a[i].Max()-a[i].Mid();
	sort(t+1,t+1+tot);
	for(int i=1;i<=tot-n/2;i++)
		ans-=t[i];
	printf("%d\n",ans);
	return ;
	
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&T);
    while(T--)
		Solve();
    return 0;

    fclose(stdin);
    fclose(stdout);

}
