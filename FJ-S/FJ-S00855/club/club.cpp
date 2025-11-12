#include<bits/stdc++.h>
using namespace std;
int t,n;
long long sum;
struct m{
	int a,b,c,o[4];
}s[100005];
bool cmp(m x,m y){
	if(x.o[1]-x.o[2]!=y.o[1]-y.o[2])return x.o[1]-x.o[2]>y.o[1]-y.o[2];
	return x.o[1]-x.o[3]>y.o[1]-y.o[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				s[i].o[1]=s[i].a;
				if(s[i].b>=s[i].c){
					s[i].o[2]=s[i].b;
					s[i].o[3]=s[i].c;
				}else{
					s[i].o[2]=s[i].c;
					s[i].o[3]=s[i].b;
				}
			}
			if(s[i].b>s[i].a&&s[i].b>s[i].c){
				s[i].o[1]=s[i].b;
				if(s[i].a>=s[i].c){
					s[i].o[2]=s[i].a;
					s[i].o[3]=s[i].c;
				}else{
					s[i].o[2]=s[i].c;
					s[i].o[3]=s[i].a;
				}
			}
			if(s[i].c>s[i].b&&s[i].c>s[i].a){
				s[i].o[1]=s[i].c;
				if(s[i].b>=s[i].a){
					s[i].o[2]=s[i].b;
					s[i].o[3]=s[i].a;
				}else{
					s[i].o[2]=s[i].a;
					s[i].o[3]=s[i].b;
				}
			}
		}
		sort(s+1,s+n+1,cmp);
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			if(s[i].a>s[i].b&&s[i].a>s[i].c){
				if(s1<n/2){
					s1++;
					sum+=s[i].a;
				}else{
					if(s[i].b>=s[i].c){
						if(s2<n/2){
							s2++;
							sum+=s[i].b;
						}else{
							s3++;
							sum+=s[i].c;
						}
					}else{
						if(s3<n/2){
							s3++;
							sum+=s[i].c;
						}else{
							s2++;
							sum+=s[i].b;
						}
					}
				}
			}else if(s[i].b>s[i].a&&s[i].b>s[i].c){
				if(s2<n/2){
					s2++;
					sum+=s[i].b;
				}else{
					if(s[i].a>=s[i].c){
						if(s1<n/2){
							s1++;
							sum+=s[i].a;
						}else{
							s3++;
							sum+=s[i].c;
						}
					}else{
						if(s3<n/2){
							s3++;
							sum+=s[i].c;
						}else{
							s1++;
							sum+=s[i].a;
						}
					}
				}
			}else if(s[i].c>s[i].a&&s[i].c>s[i].b){
				if(s3<n/2){
					s3++;
					sum+=s[i].c;
				}else{
					if(s[i].a>=s[i].b){
						if(s1<n/2){
							s1++;
							sum+=s[i].a;
						}else{
							s2++;
							sum+=s[i].b;
						}
					}else{
						if(s2<n/2){
							s2++;
							sum+=s[i].b;
						}else{
							s1++;
							sum+=s[i].a;
						}
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

