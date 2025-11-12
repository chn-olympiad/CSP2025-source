#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,p[30],s[500005],ans,su,cd,j;
map<int,int>q;
int f(int x,int y){
	string sx,sy;
	if(x==0)	return y;
	if(y==0)	return x;
	int sum=0;
	for(int i=20;i>=0;i--){
		if(x>=p[i]){
			x-=p[i];
			sx+='1';
		}
		else sx+='0';
	}
	for(int i=20;i>=0;i--){
		if(y>=p[i]){
			y-=p[i];
			sy+='1';
		}
		else sy+='0';
	}
	for(int i=0;i<sx.size();i++){
		if(sx[i]!=sy[i])	sum+=p[sx.size()-i-1];
	}
	return sum;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=20;i++)	p[i]=p[i-1]*2;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=f(s[i-1],a[i]);
		if(a[i]==k){
			q[i]=i;
			ans++;
			su++;
		}
	}
	for(int i=2;i<=n;i++){
		cd=0;
		if(su+i>n)	break;
		if(!q.empty()){
			auto g=q.upper_bound(i);
			if(g==q.begin())	j=i;
			else{
				g--;
				j=g->first;
			}
		}
		else j=i;
		for(;j<=n;j++){
			if(q.find(j)!=q.end()){
				cd=i-1;
				j=q[j];
				continue;
			}
			if(cd!=0){
				cd--;
				continue;
			}
			if(f(s[j],s[j-i])==k){
				q[j-i+1]=j;
				ans++;
				su+=i;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
