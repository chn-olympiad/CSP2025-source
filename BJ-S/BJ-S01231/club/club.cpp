#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[100005],b[100005],c[100005],x[100005][3],y[100005],ans[15],coount=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int cnta=1,cntb=1,cntc=1;
	while(t--){
		long long sum=0;
		cin>>n;
		cnta=1;
		cntb=1;
		cntc=1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=1;i<=n;i++){
			cin>>x[i][0]>>x[i][1]>>x[i][2];
			long long mmax=max(x[i][0],max(x[i][1],x[i][2]));
			if(mmax == x[i][0]){
				a[cnta]=i;
				sum+=x[i][0];
				cnta++;
			}
			else if(mmax == x[i][1]){
				sum+=x[i][1];
				b[cntb]=i;
				cntb++;
			}
			else if(mmax == x[i][2]){
				sum+=x[i][2];
				c[cntc]=i;
				cntc++;
			}
		}
	//	for(int i=1;i<cnta;i++) cout<<a[i]<<" ";
	//	cout<<endl;
	//	for(int i=1;i<cntb;i++) cout<<b[i]<<" ";
	//	cout<<endl;
	//	for(int i=1;i<cntc;i++) cout<<c[i]<<" ";
	//	cout<<endl;
		cnta--;
		cntb--;
		cntc--;
		
		if(cnta>n/2){
			for(int i=1;i<=cnta;i++){
				y[i]=max(x[a[i]][1],x[a[i]][2]);
				y[i]=x[a[i]][0]-y[i];
			}
			sort(y+1,y+cnta+1);
			for(int i=1;cnta>n/2;i++){
				sum=sum-y[i];
				cnta--;
			}
			
		}
		else if(cntb>n/2){
			for(int i=1;i<=cntb;i++){
				y[i]=max(x[b[i]][0],x[b[i]][2]);
				y[i]=x[b[i]][1]-y[i];
			}
			sort(y+1,y+cntb+1);
			for(int i=1;cntb>n/2;i++){
				sum=sum-y[i];
				cntb--;
			}
			
		}
		else if(cntc>n/2){
			for(int i=1;i<=cntc;i++){
				y[i]=max(x[c[i]][1],x[c[i]][0]);
				y[i]=x[c[i]][2]-y[i];
			}
			sort(y+1,y+cntc+1);
			for(int i=1;cntc>n/2;i++){
				sum=sum-y[i];
				cntc--;
			}
			
		}
		ans[++coount]=sum;
	}
	for(long long i=1;i<=coount;i++) cout<<ans[i]<<endl;
	return 0;
}
