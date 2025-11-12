#include<bits/stdc++.h>
using namespace std;
struct s{
	int a,b;
};
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n=0,a=0,b=0,c=0,ans=0;
		cin >> n;
		int x[n][3];
		struct s z[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin >> x[i][j];
			}
		}for(int i=0;i<n;i++){
			if(x[i][0]>=x[i][1]&&x[i][0]>=x[i][2]){
				z[i].a=x[i][0];
				z[i].b=0;
			}else if(x[i][1]>=x[i][0]&&x[i][1]>=x[i][2]){
				z[i].a=x[i][1];
				z[i].b=1;
			}else{
				z[i].a=x[i][2];
				z[i].b=2;
			}
		}int lm=999999;
		bool q[n]={1};
		for(int i=0;i<n;i++){
			q[i]=1;
		}
		for(int j=0;j<n;j++){
		    int l=0,la=0,lb;
		    for(int i=0;i<n;i++){
			    if(z[i].a>l&&q[i]==1){
				    l=z[i].a;
				    la=i;
				    lb=z[i].b;
			}}lm=l;
			if(lb==0&&a<n/2){
				ans+=l;
				a++;
				q[la]=0;
			}else if(lb==1&&b<n/2){
				ans+=l;
				b++;
				q[la]=0;
			}else if(lb==2&&c<n/2){
				ans+=l;
				c++;
				q[la]=0;
			}
		}struct s u[n];
		for(int i=0;i<n;i++){
			u[i].a=-1;
		}
		for(int i=0;i<n;i++){
			if(x[i][0]>=x[i][1]&&x[i][0]>=x[i][2]&&q[i]==1){
                if(x[i][1]>x[i][2]){
                	u[i].a=x[i][1];
                	u[i].b=1;
				}else{
					u[i].a=x[i][2];
					u[i].b=2;
				}
			}else if(x[i][1]>=x[i][0]&&x[i][1]>=x[i][2]&&q[i]==1){
                if(x[i][0]>x[i][2]){
                	u[i].a=x[i][0];
                	u[i].b=0;
				}else{
					u[i].a=x[i][2];
					u[i].b=2;
				}
			}else if(q[i]==1){
                if(x[i][0]>x[i][1]){
                	u[i].a=x[i][0];
                	u[i].b=0;
				}else{
					u[i].a=x[i][1];
					u[i].b=1;
				}
			}
		}
		for(int j=0;j<n;j++){
		    int l=0,la=0,lb;
		    for(int i=0;i<n;i++){
			    if(u[i].a>l&&q[i]==1){
				    l=u[i].a;
				    la=i;
				    lb=u[i].b;
			}}lm=l;
			if(lb==0&&a<n/2){
				ans+=l;
				a++;
				q[la]=0;
			}else if(lb==1&&b<n/2){
				ans+=l;
				b++;
				q[la]=0;
			}else if(lb==2&&c<n/2){
				ans+=l;
				c++;
				q[la]=0;
			}
		}
		struct s e[n];
		for(int i=0;i<n;i++){
			e[i].a=-1;
		}
		for(int i=0;i<n;i++){
			if(x[i][0]>=x[i][1]&&x[i][0]>=x[i][2]&&q[i]==1){
                if(x[i][1]>x[i][2]){
                	e[i].a=x[i][2];
                	e[i].b=2;
				}else{
					e[i].a=x[i][1];
					e[i].b=1;
				}
			}else if(x[i][1]>=x[i][0]&&x[i][1]>=x[i][2]&&q[i]==1){
                if(x[i][0]>x[i][2]){
                	e[i].a=x[i][2];
                	e[i].b=2;
				}else{
					e[i].a=x[i][0];
					e[i].b=0;
				}
			}else if(q[i]==1){
                if(x[i][0]>x[i][1]){
                	e[i].a=x[i][1];
                	e[i].b=1;
				}else{
					e[i].a=x[i][0];
					e[i].b=0;
				}
			}
		}
		for(int j=0;j<n;j++){
		    int l=0,la=0,lb;
		    for(int i=0;i<n;i++){
			    if(e[i].a>l&&q[i]==1){
				    l=e[i].a;
				    la=i;
				    lb=e[i].b;
			}}lm=l;
			if(lb==0&&a<n/2){
				ans+=l;
				a++;
				q[la]=0;
			}else if(lb==1&&b<n/2){
				ans+=l;
				b++;
				q[la]=0;
			}else if(lb==2&&c<n/2){
				ans+=l;
				c++;
				q[la]=0;
			}
		}
		cout << ans;
	}
	return 0;
}
