#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	int a,b,c;
}arr[N];
int t,num,n;
int number[N],k;
void dfs(int a1,int a2,int a3,int li,int i,int ans){
	int a,b,c;
	a=arr[i].a;
	b=arr[i].b;
	c=arr[i].c;
	if(i==n+1){
		num=max(ans,num);
		return ;
	}
	if(a1<li) dfs(a1+1,a2,a3,li,i+1,ans+a);
	if(a2<li) dfs(a1,a2+1,a3,li,i+1,ans+b);
	if(a3<li) dfs(a1,a2,a3+1,li,i+1,ans+c);
	dfs(a1,a2,a3,li,i+1,ans);
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
    	scanf("%d",&n);
    	k=0;
    	for(int j=1;j<=n;++j){
			scanf("%d%d%d",&arr[j].a,&arr[j].b,&arr[j].c);
			if(arr[j].b==0&&arr[j].c==0){
				k++;
				number[k]=arr[j].a;
			}
		}
		if(k==n){
			sort(number+1,number+1+n);
			int x;
			for(int ii=n/2+1;ii<=n;++ii) x+=number[ii];
			printf("%d",x);
			return 0;
		}
    	arr[n+1].a=0,arr[n+1].b=0,arr[n+1].c=0;
    	num=0;
    	dfs(0,0,0,n/2,1,0);
    	printf("%d\n",num);
	}
	return 0;
}
