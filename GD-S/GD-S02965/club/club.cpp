#include<bits/stdc++.h>
using namespace std;

long long int a[100005][5],sf,ss,st,b[100005];
int t,n;

long long int mxcheck(long long int a,long long int b,long long int c){
	if(a>=b && a>=c) return a;
	if(b>=a && b>=c) return b;
	if(c>=a && c>=b) return c;
}

long long int mncheck(long long int a,long long int b,long long int c){
	if(a>b && a<c || c<a && a<b) return a;
	if(b>a && b<c || c<b && b<a) return b;
	if(c>a && c<b || b<c && c<a) return c; 
}

bool cmp(long long int a,long long int b){
	return a>b;
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int pos=mxcheck(a[i][1],a[i][2],a[i][3]);
			if(pos==a[i][1]) {
				sf++;
				a[i][4]=1;
				a[i][2]-=a[i][1];
				a[i][3]-=a[i][1];
			}
			else if(pos==a[i][2]){
				ss++;
				a[i][4]=2;
				a[i][1]-=a[i][2];
				a[i][3]-=a[i][2];
			}
			else{
				st++;
				a[i][4]=3;
				a[i][1]-=a[i][3];
				a[i][2]-=a[i][3];
			}
		}
		//cout<<sf<<" "<<ss<<" "<<st<<endl;
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][4]];
		}	
		//cout<<ans<<endl;
		if(sf<=n/2 && ss<=n/2 && st<=n/2){
			cout<<ans<<endl;
		}
		else{
			long long int more=mxcheck(sf,st,ss),pos=1,p;
			if(more==sf) p=1;
			if(more==st) p=3;
			if(more==ss) p=2;
			for(int i=1;i<=n;i++){
				if(a[i][4]==p){
					b[pos]=mncheck(a[i][1],a[i][2],a[i][3]);
					pos++;
				}
			}
			sort(b+1,b+pos,cmp);
			for(int i=1;i<=more-n/2;i++) ans+=b[i];
			cout<<ans<<endl;
		}
		memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		sf=0,st=0,ss=0;
	}/**/
	return 0;
}
