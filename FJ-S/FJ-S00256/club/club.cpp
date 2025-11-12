#include<bits/stdc++.h>
using namespace std;
struct du{
	int ea,eb,ec,w,p;
	bool flag;
}a[100005];
int t,n,fir=0,sec=0,thi=0,ans=0;
bool cmpa(du x,du y){
	return x.ea>y.ea;
}
bool cmpb(du x,du y){
	return x.eb>y.eb;
}
bool cmpc(du x,du y){
	return x.ec>y.ec;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		fir=sec=thi=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].ea>>a[i].eb>>a[i].ec;
			if(a[i].ea>a[i].eb&&a[i].ea>a[i].ec){
				a[i].w=1;
				fir++;
				a[i].p=a[i].ea;
			}
			if(a[i].eb>a[i].ea&&a[i].eb>a[i].ec){
				a[i].w=2;
				sec++;
				a[i].p=a[i].eb;
			}
			if(a[i].ec>a[i].eb&&a[i].ec>a[i].ea){
				a[i].w=3;
				thi++;
				a[i].p=a[i].ec;
			}
		}
		if(fir>n/2){
			sort(a+1,a+n+1,cmpa);
			int i=n/2+1;
			while(a[i].w==1){
				if(a[i].eb>a[i].ec&&sec<n/2){
					a[i].w=2;
					a[i].p=a[i].eb;
					fir--;
					sec++;
				}
				else{
					a[i].w=3;
					a[i].p=a[i].ec;
					fir--;
					thi++;
				}
				i++;
			}
		}
		if(sec>n/2){
			sort(a+1,a+n+1,cmpb);
			int i=n/2+1;
			while(a[i].w==2){
				if(a[i].ea>a[i].ec&&fir<n/2){
					a[i].w=1;
					a[i].p=a[i].ea;
					fir++;
					sec--;
				}
				else{
					a[i].w=3;
					a[i].p=a[i].ec;
					sec--;
					thi++;
				}
				i++;
			}
		}
		if(thi>n/2){
			sort(a+1,a+n+1,cmpc);
			int i=n/2+1;
			while(a[i].w==3){
				if(a[i].ea>a[i].eb&&fir<n/2){
					a[i].w=1;
					a[i].p=a[i].ea;
					thi--;
					fir++;
				}
				else{
					a[i].w=2;
					a[i].p=a[i].eb;
					sec++;
					thi--;
				}
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			//cout<<a[i].w<<' ';
			ans+=a[i].p;
		}
		cout<<ans<<endl;
	}
	return 0;
}
