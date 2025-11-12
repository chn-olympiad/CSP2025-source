#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>

const int N=5e5+10;
int n,k;
int a[N];
int d[N];
pii t[N];
int tot;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool flag=true;
    int sum=0;
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	d[i]=a[i]^d[i-1];
    	if(a[i]==1) sum++;
    	if(a[i]!=1 || a[i]!=0)
    		flag=false;
	}
	if(k==1 && flag){
		cout<<sum<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
    	{
    		if((d[j]^d[i-1])==k)
				t[++tot]={i,j};		
		}
    sort(t+1,t+tot+1);
    int la=-1;
    int ans=0;
    for(int i=1;i<=tot;i++){
    	if(t[i].first>la)
    		ans++,la=t[i].second;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

