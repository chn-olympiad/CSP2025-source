#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n,k;
int a[N];
int sum,c1,ans;
bool f = true,f01 = true;

void dfs(int p,int q,int sum){
	if(p>n){
		return;
	}
	if(sum == k){
		ans = max(ans,q);
		for(int i = p+1;i<=n;i++){
			dfs(i,q+1,a[i]);
		}
	}else{
		dfs(p+1,q,a[p+1]^sum);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	srand(time(0));
	
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f = false;
		}else{
			c1++;
		}
		if(a[i]!=0 && a[i]!=1){
			f01 = false;
		}
	}
	
	//10
	if(f && k == 0){
		printf("%d",k/2);
	}else if(f01 && k<=1){ //15
		if(k == 1){
			printf("%d",c1);
		}else{
			int c = 0;
			for(int i = 1;i<=n;){
				if(a[i] == 0){
					c++;
					i++;
				}else{
					if(i!=n && a[i] == 1 && a[i+1] == 1){
						i+=2;
						c++;
					}else{
						i++;
					}
				}
			}
			printf("%d",c);
		}
	}else{
//		cout<<rand()%n;
        dfs(1,1,a[1]);
        printf("%d",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
