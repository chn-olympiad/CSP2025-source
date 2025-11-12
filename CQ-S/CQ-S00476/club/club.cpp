#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c;
	int sum=0;
}ans[100001];
int n;
bool cmp(node x,node y){
	if (x.sum==y.sum){
		if (x.a==y.a){
			if(x.b==y.b){
				if(x.c==y.c){
					return x.c<y.c;
				}else{
					return x.c>y.c;
				}
			}else{
				return x.b>y.b;
			}
		}else{
			return x.a>y.a;
		}
	}else{
		return x.sum>y.sum;
	}
}
bool A(){
	for (int i=1;i<=n;i++){
		if (ans[i].c!=0 || ans[i].b!=0) return 0;
	}
	return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		for (int i=1;i<=10001;i++) ans[i].sum=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>ans[i].a>>ans[i].b>>ans[i].c;
			ans[i].sum+=ans[i].a+ans[i].c+ans[i].b; 
		}
		
		sort(ans+1,ans+1+n,cmp);
		if (A()){
			int sum=0;
			for (int i=1;i<=n/2;i++){
				sum+=ans[i].a;
			} 
			cout<<sum;
			continue;
		}
		else{
			if (n==2){
				cout<<max(ans[1].a+ans[2].b,max(ans[1].a+ans[2].c,max(ans[1].b+ans[2].c,max(ans[1].b+ans[2].a,max(ans[1].c+ans[2].a,ans[1].c+ans[2].b)))));
			}
			if (n==4){
				int xa=n/2,xb=n/2,xc=n/2;
				int maxx=INT_MIN;
				for (int i=1;i<=3;i++){
					for (int j=1;j<=3;j++){
						for (int k=1;k<=3;k++){
							int sum=0;
							for (int l=1;l<=3;l++){
								if (i==1 && xa>0){
									sum+=ans[1].a;
									xa--;
								}
								else if (i==2 && xb>0){
									sum+=ans[1].b;
									xb--;
								}
								else if (i==3 && xc>0){
									sum+=ans[1].c;
									xc--;
								}
								if (j==1 && xa>0){
									sum+=ans[2].a;
									xa--;
								}
								else if (j==2 && xb>0){
									sum+=ans[2].b;
									xb--;
								}
								else if (j==3 && xc>0){
									sum+=ans[2].c;
									xc--;
								}
								if (k==1 && xa>0){
									sum+=ans[3].a;
									xa--;
								}
								else if (k==2 && xb>0){
									sum+=ans[3].b;
									xb--;
								}
								else if (k==3 && xc>0){
									sum+=ans[3].c;
									xc--;
								}
								if (l==1 && xa>0){
									sum+=ans[4].a;
									xa--;
								}
								else if (l==2 && xb>0){
									sum+=ans[4].b;
									xb--;
								}
								else if (l==3 && xc>0){
									sum+=ans[4].c;
									xc--;
								}
								maxx=max(maxx,sum);
								sum=0;
								xa=n/2,xb=n/2,xc=n/2;
							} 
						} 
					}
				}
				cout<<maxx<<endl;
			}
			else{
				
			} 
		}
	}
	return 0;
}
