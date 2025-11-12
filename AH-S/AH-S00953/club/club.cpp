#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a,b,c;
};

int n,t,s1,s2,s3;
edge ar[100005],a1[100005],a2[100005],a3[100005];

bool cmp(edge a,edge b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}

bool cmp2(edge a,edge b){
	return a.a-max(a.b,a.c)>b.a-max(b.b,b.c);
}

bool cmp3(edge a,edge b){
	return a.b-max(a.a,a.c)>b.b-max(b.a,b.c);
}

bool cmp4(edge a,edge b){
	return a.c-max(a.a,a.b)>b.c-max(b.a,b.b);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s1=0;s2=0;s3=0;
		int ans=0,cnt=0,flag=0;
		scanf("%d",&n);
		memset(ar,0,sizeof(ar));
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&ar[i].a,&ar[i].b,&ar[i].c);
			if(ar[i].a<ar[i].b&&ar[i].a<ar[i].c) flag=1;
			if(ar[i].b<ar[i].a&&ar[i].b<ar[i].c) flag=1;
			if(ar[i].c<ar[i].a&&ar[i].c<ar[i].b) flag=1;
		}
		sort(ar+1,ar+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(ar[i].a>=ar[i].b && ar[i].a>=ar[i].c){
				s1++;
				a1[s1]=ar[i];
			}
			else if(ar[i].b>=ar[i].a && ar[i].b>=ar[i].c){
				s2++;
				a2[s2]=ar[i];
			}
			else{
				s3++;
				a3[s3]=ar[i];
			}
		}
		if(s1>n/2){
			sort(a1+1,a1+s1+1,cmp2);
			for(int i=s1;i>n/2;i--){
				ans-=a1[i].a-max(a1[i].b,a1[i].c);
				s1--;
				cnt++;
			}
			if(s2+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s1+1;i<=s1+cnt;i++){
					x1=min(x1,a1[i].b-a1[i].c);
					x2=max(x2,a1[i].a-a1[i].b);
				}
				for(int i=1;i<=s2;i++){
					x1=min(x1,a2[i].b-a2[i].c);
				}
				for(int i=1;i<=s1;i++){
					x3=min(x3,a1[i].a-a1[i].c);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			else if(s3+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s1+1;i<=s1+cnt;i++){
					x1=min(x1,a1[i].c-a1[i].b);
					x2=max(x2,a1[i].a-a1[i].c);
				}
				for(int i=1;i<=s3;i++){
					x1=min(x1,a3[i].b-a3[i].c);
				}
				for(int i=1;i<=s1;i++){
					x3=min(x3,a1[i].a-a1[i].b);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			s1+=cnt;
			for(int i=1;i<=s1;i++) ans+=a1[i].a;
			for(int i=1;i<=s2;i++) ans+=a2[i].b;
			for(int i=1;i<=s3;i++) ans+=a3[i].c;
		}
		else if(s2>n/2){
			sort(a2+1,a2+s2+1,cmp3);
			for(int i=s2;i>n/2;i--){
				ans-=a2[i].b-max(a2[i].a,a2[i].c);
				s2--;
				cnt++;
			}
			if(s1+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s2+1;i<=s2+cnt;i++){
					x1=min(x1,a2[i].a-a2[i].c);
					x2=max(x2,a2[i].b-a2[i].a);
				}
				for(int i=1;i<=s1;i++){
					x1=min(x1,a1[i].a-a1[i].c);
				}
				for(int i=1;i<=s2;i++){
					x3=min(x3,a2[i].b-a2[i].c);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			else if(s3+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s2+1;i<=s2+cnt;i++){
					x1=min(x1,a2[i].c-a2[i].a);
					x2=max(x2,a2[i].b-a2[i].c);
				}
				for(int i=1;i<=s3;i++){
					x1=min(x1,a3[i].c-a3[i].a);
				}
				for(int i=1;i<=s2;i++){
					x3=min(x3,a2[i].b-a2[i].a);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			s2+=cnt;
			for(int i=1;i<=s1;i++) ans+=a1[i].a;
			for(int i=1;i<=s2;i++) ans+=a2[i].b;
			for(int i=1;i<=s3;i++) ans+=a3[i].c;
		}
		else if(s3>n/2){
			sort(a3+1,a3+s3+1,cmp4);
			for(int i=s3;i>n/2;i--){
				ans-=a3[i].c-max(a3[i].a,a3[i].b);
				s3--;
				cnt++;
			}
			if(s1+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s3+1;i<=s3+cnt;i++){
					x1=min(x1,a3[i].a-a3[i].b);
					x2=max(x2,a3[i].c-a3[i].a);
				}
				for(int i=1;i<=s1;i++){
					x1=min(x1,a1[i].a-a1[i].b);
				}
				for(int i=1;i<=s3;i++){
					x3=min(x3,a3[i].c-a3[i].b);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			else if(s2+cnt>n/2&&flag==1){
				int ans1=0,ans2=0,x1=1e9,x2=-1,x3=1e9;
				for(int i=s3+1;i<=s3+cnt;i++){
					x1=min(x1,a3[i].b-a3[i].a);
					x2=max(x2,a3[i].c-a3[i].b);
				}
				for(int i=1;i<=s2;i++){
					x1=min(x1,a2[i].b-a2[i].a);
				}
				for(int i=1;i<=s3;i++){
					x3=min(x3,a3[i].c-a3[i].a);
				}
				ans1=-x1;ans2=-x3+x2;
				ans+=max(ans1,ans2);
			}
			s3+=cnt;
			for(int i=1;i<=s1;i++) ans+=a1[i].a;
			for(int i=1;i<=s2;i++) ans+=a2[i].b;
			for(int i=1;i<=s3;i++) ans+=a3[i].c;
		}
		else{
			for(int i=1;i<=s1;i++) ans+=a1[i].a;
			for(int i=1;i<=s2;i++) ans+=a2[i].b;
			for(int i=1;i<=s3;i++) ans+=a3[i].c;
		}
		printf("%d\n",ans);
	}
	return 0;
}
