#include<bits/stdc++.h>

using namespace std;

struct node{
	int first,second,third,person,maxn;
	bool ok;
}s[114514];

struct num{
	int as,bs,cs;
}sum,ans;

int T,n,a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		sum.as=0,sum.bs=0,sum.cs=0;
		ans.as=0,ans.bs=0,ans.cs=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			s[i].first=a;
			s[i].second=b;
			s[i].third=c;
			s[i].person=i;
			s[i].maxn=max(max(s[i].first,s[i].second),s[i].third);
			s[i].ok=true;
		}
		if(n<=2){
			int pan=-1,pan1=-1,pan2=-1,pan3=-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						pan=max(s[i].first+s[j].third,s[i].first+s[j].second);
						pan1=max(s[i].second+s[j].third,s[i].second+s[j].first);
						pan2=max(s[i].third+s[j].first,s[i].third+s[j].second);
						pan3=max(max(pan,pan1),pan2);
					}
				}
			}
			printf("%d\n",pan3);
			continue;
		}
		for(int i=n;i>=1;i--){
			bool ko=true;
			for(int j=1;j<i;j++){
				if(s[j].first<s[j+1].first){
					swap(s[j],s[j+1]);
					ko=false;
				}
			}
			if(ko)break;
		}
		for(int i=1;i<=n;i++){
			if(s[i].first==s[i].maxn&&s[i].ok&&sum.as<n/2){
				s[i].ok=false;
				sum.as++;
				ans.as+=s[i].first;
			}
		}
		for(int i=n;i>=1;i--){
			bool ko=true;
			for(int j=1;j<i;j++){
				if(s[j].second<s[j+1].second){
					swap(s[j],s[j+1]);
					ko=false;
				}
			}
			if(ko)break;
		}
		for(int i=1;i<=n;i++){
			if(s[i].second==s[i].maxn&&s[i].ok&&sum.bs<n/2){
				s[i].ok=false;
				sum.bs++;
				ans.bs+=s[i].second;
			}
		}
		for(int i=n;i>1;i--){
			bool ko=true;
			for(int j=1;j<i;j++){
				if(s[j].third<s[j+1].third){
					ko=false;
					swap(s[j],s[j+1]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].third==s[i].maxn&&s[i].ok&&sum.cs<n/2){
				s[i].ok=false;
				sum.cs++;
				ans.cs+=s[i].third;
			}
		}
		/*for(int i=1;i<=n;i++){
			if(s[i].ok){
				s[i].ok=false;
				if(sum.as>=n/2){
					
				}
			}
		}*/
		printf("%d\n",ans.as+ans.bs+ans.cs);
	}
	
}
