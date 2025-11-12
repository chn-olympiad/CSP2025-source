#include <bits/stdc++.h> 
using namespace std;//怎么感觉像背包 
//要求俱乐部人数小于max，且满意度最高 ，而且这个成员放了之后不能再放 
int t;
int a[114514][5];//满意度
bool vis[114514],fu[114514]; //放没放 ,满没满 
//int a1[114514],a2[114514],a3[114514];
int num[10];
long long ans;
/*void fi(int ren,int bu,int da){
	if(pu[ren]==0&&(num[bu]<=2)){
		int cnt[5];
		int tot[5];
		if(int j=1;j<=3;j++){
			cnt[j]=j;
			tot[j]=a[i][j];
			if(tot[j]>tot[j-1]){
				swap(tot[j],tot[j-1]);
				swap(cnt[j],cnt[j-1]);
			}
		}	
		ans=max(ans+tot[3],ans);
		pu[i]=1;
		num[cnt[3]]=1;	
	}
	else if
		
	
} */
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int n=0,mn=0; 
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		cin>>n;
		mn=(n/2); 
		for(int i=1;i<=n;i++){//输入满意度 
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
		}
		//对于性质A  我脑子成浆糊了 只能写一个特殊性质让自己不爆0了  
		int tot[114514];
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++){
				tot[i]=a[i][1];
		}
		sort(tot+1,tot+n+1);
		for(int i=1;i<=mn;i++){
			ans+=tot[n--];
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
