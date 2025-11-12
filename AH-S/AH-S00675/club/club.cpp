#include<bits/stdc++.h>
using namespace std;
int t,n;
long long maxn[100005]={0};
typedef struct club{
	int a,b,c;
}club;
club s[100005];
int aloc[100005],bloc[100005],cloc[100005];
int maxa[100005],maxb[100005],maxc[100005];
int main(){
	int ans=0;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int m=n/2;
		int a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			maxn[i]=max(max(s[i].a,s[i].b),max(s[i].b,s[i].c));
			if(maxn[i]==s[i].a){
				a1++;
				aloc[a1]=i;
			}
			if(maxn[i]==s[i].b){
				b1++;
				bloc[b1]=i;
			}
			if(maxn[i]==s[i].c){
				c1++;
				cloc[c1]=i;
			}
		}
		int sum=0;
		if(a1<=m&&b1<=m&&c1<=m){
			for(int i=1;i<=n;i++){
				ans+=maxn[i];
			}
		}else{
			if(a1>m){
				for(int i=1;i<=a1;i++){
					maxa[i]=maxn[aloc[i]];
				}
				sort(maxa+1,maxa+1+a1);
				for(int i=a1;i>=a1-m+1;i--){
					ans+=maxa[i];
				}
				sum=a1-m;
				for(int i=1;i<=sum;i++){
					ans+=max(s[aloc[a1]].b,s[aloc[a1]].c);
				}
			}
			if(b1>m){
				for(int i=1;i<=b1;i++){
                                        maxb[i]=maxn[bloc[i]];
                                }
                                sort(maxb+1,maxb+1+b1);
                                for(int i=b1;i>=b1-m+1;i--){
                                        ans+=maxb[i];
                                }
				sum=b1-m;
				for(int i=1;i<=sum;i++){
                                        ans+=max(s[bloc[a1]].a,s[bloc[a1]].c);
                                }

			}
			if(c1>m){
				for(int i=1;i<=c1;i++){
                                        maxc[i]=maxn[cloc[i]];
                                }
                                sort(maxc+1,maxc+1+c1);
                                for(int i=c1;i>=c1-m+1;i--){
                                        ans+=maxc[i];
                                }
				sum=c1-m;
				for(int i=1;i<=sum;i++){
                                        ans+=max(s[cloc[c1]].a,s[cloc[c1]].b);
                                }

			}
		}

		cout<<ans<<endl;
	}
	return 0;
}	
