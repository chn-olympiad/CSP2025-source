//GZ-S00293 毛俊程 遵义市第四中学
#include<bits/stdc++.h>
using namespace std;
int t;
struct aa{
	int a,b,c;
	int dx;
	int max1,max2;
}s[100005],ss[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a1=0,b1=0,c1=0,sum=0,b[100005][3],v=n/2,z=0,x=-1;
		memset(s,0,sizeof(s));
	    for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].dx=max(abs(max(s[i].a,s[i].b)-max(s[i].b,s[i].c)),abs(max(s[i].a,s[i].c)-max(s[i].b,s[i].c)));
			s[i].max1=max(s[i].a,max(s[i].b,s[i].c));
			s[i].max2=min(max(s[i].a,s[i].b),min(max(s[i].a,s[i].c),max(s[i].b,s[i].c)));
			if(s[i].max1==s[i].a) a1++;
			if(s[i].max1==s[i].b) b1++;
			if(s[i].max1==s[i].c) c1++;
		}
		for(int i=1;i<=100001;i++) b[i][0]=-1;
		memset(ss,0,sizeof(ss));
		if(a1>v){
			for(int i=1;i<=n;i++){
				if(s[i].max1==s[i].a){
				    b[s[i].dx][0]=s[i].dx;
				    b[s[i].dx][1]++;
				    int p=1;
				    for(int j=1;j<b[s[i].dx][1];j++) p*=10;
				    b[s[i].dx][2]=(i*p)+b[s[i].dx][2];
				    x=max(x,s[i].dx);
			    }
			}
			for(int i=1;i<=x;i++){
				if(b[i][0]!=-1){
					for(int j=1;j<=b[i][1];j++){
						int o=b[i][2]%10;
						b[i][2]/=10;
						ss[++z].max1=s[o].max1;
					    ss[z].max2=s[o].max2;
					    ss[z].dx=s[o].dx;
					    ss[z].a=s[o].a;
					}
				}
			}
			for(int i=n;i>=1;i--){
				if(ss[i].max1==ss[i].a&&v>0){
					v--;
					sum+=ss[i].max1;
				}
				else if(ss[i].max1!=ss[i].a) sum+=ss[i].max1;
				else sum+=ss[i].max2;
			}
		}
		if(b1>v){
			for(int i=1;i<=n;i++){
				if(s[i].max1==s[i].b){
				    b[s[i].dx][0]=s[i].dx;
				    b[s[i].dx][1]++;
				    int p=1;
				    for(int j=1;j<b[s[i].dx][1];j++) p*=10;
				    b[s[i].dx][2]=(i*p)+b[s[i].dx][2];
				    x=max(x,s[i].dx);
			    }
			}
			for(int i=1;i<=x;i++){
				if(b[i][0]!=-1){
					for(int j=1;j<=b[i][1];j++){
						int o=b[i][2]%10;
						b[i][2]/=10;
						ss[++z].max1=s[o].max1;
					    ss[z].max2=s[o].max2;
					    ss[z].dx=s[o].dx;
					    ss[z].b=s[o].b;
					}
				}
			}
			for(int i=n;i>=1;i--){
				if(ss[i].max1==ss[i].b&&v>0){
					v--;
					sum+=ss[i].max1;
				}
				else if(ss[i].max1!=ss[i].b) sum+=ss[i].max1;
				else sum+=ss[i].max2;
			}
		}
		if(c1>v){
			for(int i=1;i<=n;i++){
				if(s[i].max1==s[i].c){
				    b[s[i].dx][0]=s[i].dx;
				    b[s[i].dx][1]++;
				    int p=1;
				    for(int j=1;j<b[s[i].dx][1];j++) p*=10;
				    b[s[i].dx][2]=(i*p)+b[s[i].dx][2];
				    x=max(x,s[i].dx);
			    }
			}
			for(int i=1;i<=x;i++){
				if(b[i][0]!=-1){
					for(int j=1;j<=b[i][1];j++){
						int o=b[i][2]%10;
						b[i][2]/=10;
						ss[++z].max1=s[o].max1;
					    ss[z].max2=s[o].max2;
					    ss[z].dx=s[o].dx;
					    ss[z].c=s[o].c;
					}
				}
			}
			for(int i=n;i>=1;i--){
				if(ss[i].max1==ss[i].c&&v>0){
					v--;
					sum+=ss[i].max1;
				}
				else if(ss[i].max1!=ss[i].c) sum+=ss[i].max1;
				else sum+=ss[i].max2;
			}
		}
		if(a1<=v&&b1<=v&&c1<=v){
			for(int i=1;i<=n;i++){
				sum+=s[i].max1;
			}
		}
		cout<<sum<<endl;
	}
    return 0;
} 
