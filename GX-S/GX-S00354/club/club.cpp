#include<cstdio>
#include<algorithm>
#include<queue>
int t,n,sum=0,cnt=0,l=0,s=0;
std::priority_queue<int,std::vector<int>,std::greater<int> > pr;
struct N{
	int b,c,d;
}a[114514];
bool cmp1(N x,N y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1,ai0;i<=n;sum+=ai0,a[i].b-=ai0,a[i].c-=ai0,a[i].d=a[i].b-a[i].c,i++) scanf("%d%d%d",&ai0,&a[i].b,&a[i].c);
		std::sort(a+1,a+n+1,cmp1);
		s=0;
		while(l){
			pr.pop();
			l--;
		}
		for(cnt=n;cnt>n/2;cnt--){
			if(a[cnt].d<0) break;
			s+=a[cnt].b;
		}
		for(;cnt;cnt--){
			if(l<n/2){
				pr.push(a[cnt].c);
				s+=a[cnt].c,l++;
			}
			else if(pr.top()<a[cnt].c){
				s+=a[cnt].c-pr.top();
				pr.pop();
				pr.push(a[cnt].c);
			}
		}
		printf("%d",sum+s);
		if(t) printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
