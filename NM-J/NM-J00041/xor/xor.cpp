//xian zhao yi ge jiu neng dui shang de
//ran hou jin ke neng de wang shao zhao
#include<bits/stdc++.h>
using namespace std;
long long k,n,a[100005],cnt;
bool check(int x,int y){
	for(int i=x;i<=y;++i){
		if(a[i]==-1){
			return false;
		}
	}
	return true;
}
bool deal(int x,int y){
	int result=a[x];
	for(int i=x+1;i<=y;++i){
		result^=a[i];
	}
	if(result==k){
		for(int i=x;i<=y;++i){
			a[i]=-1;
		}
		return true;
	}
	return false;
}
int main(){
	freopen("nor.in","r",stdin);
	freopen("nor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			cnt++;
			a[i]=-1;
		}
	}
	for(int i=1;i<=n-1;++i){
		for(int j=1;j+i<=n;++j){
			if(check(j,j+i)){
				if(deal(j,j+i)){
					cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
