#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c,cz;
}s[100010];
bool cmp(node x,node y){
	return x.cz>y.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int x=max(s[i].a,max(s[i].b,s[i].c)),y;
			if(x==s[i].a){
				y=max(s[i].b,s[i].c);
			}
			else if(x==s[i].b){
				y=max(s[i].a,s[i].c);
			}
			else{
				y=max(s[i].a,s[i].b);
			}
			s[i].cz=x-y;
		}
		sort(s+1,s+n+1,cmp);
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<" "<<s[i].cz<<endl;
//		}
//		cout<<endl<<endl;
		int suma=0,sumb=0,sumc=0,sum=0;
		for(int i=1;i<=n/2;i++){
			int x=max(s[i].a,max(s[i].b,s[i].c));
			sum+=x;
			if(x==s[i].a){
				suma++;
			}
			else if(x==s[i].b){
				sumb++;
			}
			else{
				sumc++;
			}
		}
		for(int i=n/2+1;i<=n;i++){
			int x=max(s[i].a,max(s[i].b,s[i].c)),y;
			if(x==s[i].a){
				y=max(s[i].b,s[i].c);
			}
			else if(x==s[i].b){
				y=max(s[i].a,s[i].c);
			}
			else{
				y=max(s[i].a,s[i].b);
			}
			if(x==s[i].a){
				if(suma==n/2){
					sum+=y;
					if(y==s[i].b){
						sumb++;
					}
					else{
						sumc++;
					}
				}
				else{
					sum+=x;
					suma++;
				}
			}
			else if(x==s[i].b){
				if(sumb==n/2){
					sum+=y;
					if(y==s[i].a){
						suma++;
					}
					else{
						sumc++;
					}
				}
				else{
					sum+=x;
					sumb++;
				}
			}
			else{
				if(sumc==n/2){
					sum+=y;
					if(y==s[i].a){
						suma++;
					}
					else{
						sumb++;
					}
				}
				else{
					sum+=x;
					sumc++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
