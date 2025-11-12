#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int a,a1,a2,maxx;
}s[100010],f[100010];
bool cmp(node x,node y){
	return x.maxx>y.maxx;
}
bool cmp1(node x,node y){
	return x.a2>y.a2;
}
bool cmp2(node x,node y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			s[i].a1=b-a,s[i].a2=c-a,s[i].a=a;
			s[i].maxx=max(s[i].a1,s[i].a2);
		}
		sort(s+1,s+n+1,cmp);
//		for(int i=1;i<=n;i++)
//			printf("%d %d %d %d\n",s[i].a,s[i].a1,s[i].a2,s[i].maxx);
		bool flag=0,flag1=0;
		int pos=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			if(n2==n/2){
				sort(s+i,s+n+1,cmp1);
				for(int j=i;j<=n;j++){
					if(s[j].a2<0)
						flag1=1;
					if(flag1&&j>n/2){
						pos=j;
						break;
					}
					ans+=s[j].a+s[j].a2;
				}
				break;
			}
			if(n3==n/2){
				sort(s+i,s+n+1,cmp2);
				for(int j=i;j<=n;j++){
					if(s[j].a1<0)
						flag1=1;
					if(flag1&&j>n/2){
						pos=j;
						break;
					}
					ans+=s[j].a+s[j].a1;
				}
				break;
			}
			if(s[i].maxx<0) flag=1;
			if(flag&&i>n/2){
				pos=i;
				break;
			}
			if(s[i].maxx==s[i].a1)
				if(n2<n/2)
					n2++;
			if(s[i].maxx==s[i].a2)
				if(n3<n/2)
					n3++;
			ans+=s[i].a+s[i].maxx;
		}
//		cout<<pos<<endl;
		for(int i=pos;i<=n;i++)
			ans+=s[i].a;
		cout<<ans<<endl;
		ans=0;
	}



	return 0;
}

