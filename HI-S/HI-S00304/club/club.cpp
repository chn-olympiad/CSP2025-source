#include<bits/stdc++.h>
using namespace std;
int t,n;
int a;
int b;
int c;
int ax[100005];
int bx[100005];
int cx[100005];
int la=0,lb=0,lc=0;
long long sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		la=0;
		lb=0;
		lc=0;
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			sum+=max(a,max(b,c));
			if(a>=b&&a>=c){
				ax[la]=a-max(b,c);
				la++;
			}
			else if(b>=a&&b>=c){
				bx[lb]=b-max(a,c);
				lb++;
			}
			else{
				cx[lc]=c-max(a,b);
				lc++;
			}
		}
		sort(ax,ax+la);
		sort(bx,bx+lb);
		sort(cx,cx+lc);
		if(la>n/2){
			int l=la-(n/2);
			for(int i=0;i<l;i++){
				sum-=ax[i];
			}
		}
		else if(lb>n/2){
			int l=lb-(n/2);
			for(int i=0;i<l;i++){
				sum-=bx[i];
			}
		}
		else if(lc>n/2){
			int l=lc-(n/2);
			for(int i=0;i<l;i++){
				sum-=cx[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
