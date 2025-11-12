#include <bits/stdc++.h>
using namespace std;
int n,k,tot=0;
int num[1010],mini=1145141;
int formxor[1010][1010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++) scanf("%d",&num[i]);
    for(int i=1; i<=n; i++){
		int res=num[i];
		if(res==k) formxor[i][i]=1,mini=min(mini,i);
		for(int j=i+1; j<=n; j++){
			res=res^num[j];
			if(res==k)formxor[i][j]=1,mini=min(mini,i);
		}
	}
	int mans=-1;
	for(int i=mini; i<=n; i++){
		int t=i,ans=0;
		while(true){
			int zt=0,nt;
			for(int j=t; j<=n; j++){
				if(formxor[t][j]==1 && zt==0) nt=j,zt=1;
			}
			if(zt==0) break;
			ans++;
			t=nt+1;
		}
		mans=max(mans,ans);
	}
	printf("%d",mans);
	return 0;
}
