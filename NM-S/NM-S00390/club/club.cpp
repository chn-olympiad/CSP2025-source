#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans[5];
bool visit[100005];

int find(int j,int num){
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i][j]==num&&visit[i]==false){
			return i;
		}
	}
	return -1;
}

void dfs(int ci){
	int cnt[3];
	for(int i=0;i<=3;i++)	cnt[i]=0;
	vector<int> tmp(n);
	int max,pos,p=n;
	while(p!=0){
		for(int i=ci;i<=3;i++){
			if(cnt[i]>n/2)	continue;
			else{
				for(int j=1;j<=n;j++){
					tmp[j]=a[j][i];
				}
				sort(tmp.begin(),tmp.end());
				for(int k=n;k>0;k--){
					max=tmp[k];
					pos=find(i,max);
					if(pos==-1){
						continue;
					}else{
						break;
					}
				}
				ans[i]=max;
				if(p==0)	break;
				else{
					p--;
					cnt[i]++;
				}
			}
		}
	}
}

int main(){
    freopen("./club.in",r,stdin);
    freopen("./club.out",w,stdout);
    scanf("%d",&t);
    for(;t>=1;--t){
        int oans=0;

		scanf("%d",&n);
        for(int i=1;i<=n;i++){
        	scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1);
		for(int i=1;i<=3;i++){
			oans+=ans[i];
		}
		printf("%d\n",oans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
