#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;	
		int sum=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int b1=n/2,b2=n/2,b3=n/2;
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]){
				if(a[i]>=c[i]){
					if(b1>0){
						b1--;
						sum+=a[i];
						a[i]=0;
						sort(a+1,a+1+n,cmp);
						continue;
					}else{
						if(b[i]>=c[i]){
							if(b2>0){
								b2--;
								sum+=b[i];
								b[i]=0;
								sort(b+1,b+1+n,cmp);
								continue;
							}else{
								b3--;
								sum+=c[i];
								c[i]=0;
								sort(c+1,c+1+n,cmp);
								continue;
							}
						}else{
							if(b3>0){
								b3--;
								sum+=c[i];
								c[i]=0;
								sort(c+1,c+1+n,cmp);
								continue;
							}else{
								b2--;
								sum+=b[i];
								b[i]=0;
								sort(b+1,b+1+n,cmp);
								continue;
							}							
						}
					}
				}else{
					if(b3>0){
						b3--;
						sum+=c[i];
						c[i]=0;	
						sort(c+1,c+1+n,cmp);
						continue;
					}else if(b1>0){
						b1--;
						sum+=a[i];
						a[i]=0;
						sort(a+1,a+1+n,cmp);
						continue;
					}else {
						b2--;
						sum+=b[i];
						b[i]=0;
						sort(b+1,b+1+n,cmp);
						continue;
					}
				}
			}else{
				if(a[i]>=c[i]){
					if(b2>0){
						b2--;
						sum+=b[i];	
						b[i]=0;
						sort(b+1,b+1+n,cmp);
						continue;					
					}else{
						if(b1>0){
							b1--;
							sum+=a[i];
							a[i]=0;
							sort(a+1,a+1+n,cmp);
							continue;
							}else{
								b3--;
								sum+=c[i];
								c[i]=0;
								sort(c+1,c+1+n,cmp);
								continue;
							}
						}
					}else{
					if(b2>0){
						b2--;
						sum+=b[i];	
						b[i]=0;	
						sort(b+1,b+1+n,cmp);
						continue;		
					}else if(b3>0){
						b3--;
						sum+=c[i];
						c[i]=0;
						sort(c+1,c+1+n,cmp);
						continue;
					}else{
						b1--;
						sum+=a[i];
						a[i]=0;
						sort(a+1,a+1+n,cmp);
						continue;
					}

				}
			}
			sort(a+1,a+1+n,cmp);
			sort(b+1,b+1+n,cmp);
			sort(c+1,c+1+n,cmp);
		}
		cout<<sum;
	}
	return 0;
}

