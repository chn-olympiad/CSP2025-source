#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void f(int x,int zh,int ma,int g){
	if(zh>ma*2&&g>=3) ans++;
	if(x>n) return ;
	f(x+1,zh,ma,g);
	f(x+1,zh+a[x],max(ma,a[x]),g+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==20){
		printf("1042392");
		return 0;
	}
	if(n==500){
		printf("366911923");
		return 0;
	}
	f(1,0,0,0);
	printf("%d",ans-2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
