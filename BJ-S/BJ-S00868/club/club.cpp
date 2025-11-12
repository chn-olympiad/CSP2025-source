#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	int a,b,c;
}m[N];
int check(node x){
	int a=x.a,b=x.b,c=x.c;
	if(a>b){
		swap(a,b);
	}
	if(a>c){
		swap(a,c);
	}
	if(b>c){
		swap(c,b);
	}
	return c-b;
}
bool cmp(node x,node y){
	int a=check(x);
	int b=check(y);
	if(a!=b){
		return a>b;
	}
	int maxx=max(x.a,max(x.b,x.c));
	int minx=max(y.a,max(y.b,y.c));
	return maxx>minx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&m[i].a,&m[i].b,&m[i].c);
		}
		sort(m+1,m+n+1,cmp);
		int cnt1=0,cnt2=0,cnt3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			int a=m[i].a,b=m[i].b,c=m[i].c;
			int maxx=max(a,max(b,c));
			if(maxx==a){
				if(cnt1<n/2){
					sum+=a;
					cnt1++;
				}
				else{
					maxx=max(b,c);
					if(maxx==b){
						cnt2++;
						sum+=b;
					}
					else{
						cnt3++;
						sum+=c;
					}
				}
			}
			else if(maxx==b){
				if(cnt2<n/2){
					sum+=b;
					cnt2++;
				}
				else{
					maxx=max(a,c);
					if(maxx==a){
						cnt1++;
						sum+=a;
					}
					else{
						cnt3++;
						sum+=c;
					}
				}
			}
			else if(maxx==c){
				if(cnt3<n/2){
					sum+=c;
					cnt3++;
				}
				else{
					maxx=max(a,b);
					if(maxx==a){
						cnt1++;
						sum+=a;
					}
					else{
						cnt2++;
						sum+=b;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
