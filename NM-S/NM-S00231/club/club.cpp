#include<bits/stdc++.h> 
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int T,n,res,ans,cnt1,cnt2,cnt3;
int a1[N],a2[N],a3[N];
void dfs(int u){
	if(u==n+1){
		res=max(res,ans);
		return ;
	}
	if(cnt1<n/2){
		cnt1++;
		ans+=a1[u];
		dfs(u+1);
		ans-=a1[u];
		cnt1--;
	}
	if(cnt2<n/2){
		cnt2++;
		ans+=a2[u];
		dfs(u+1);
		ans-=a2[u];
		cnt2--;
	}
	if(cnt3<n/2){
		cnt3++;
		ans+=a3[u];
		dfs(u+1);
		ans-=a3[u];
		cnt3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		res=0,ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		bool A=0,B=0,C=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i])A=1;
			if(a2[i])B=1;
			if(a3[i])C=1;
		}
		if(B==0&&C==0){
			sort(a1+1,a1+1+n);
			int res=0;
			int m=n/2+1;
			while(m<=n){
				res+=a1[m];
				m++;
			}
			continue;
		}
		if(A==0&&C==0){
			sort(a2+1,a2+1+n);
			int res=0;
			int m=n/2+1;
			while(m<=n){
				res+=a2[m];
				m++;
			}
			continue;
		}
		if(A==0&&B==0){
			sort(a3+1,a3+1+n);
			int res=0;
			int m=n/2+1;
			while(m<=n){
				res+=a3[m];
				m++;
			}
			continue;
		}
		dfs(1);
		cout<<res<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
