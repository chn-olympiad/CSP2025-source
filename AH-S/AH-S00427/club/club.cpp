#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100015],b[100015],c[100015],lop[100015],w=0,e=0,r=0,p=0;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		w=0,e=0,r=0,p=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]){
				if(a[i]>=c[i]) w++,ans=ans+a[i];	
				else r++,ans=ans+c[i];
			}
			else{
				if(b[i]>=c[i]) e++,ans=ans+b[i];		
				else r++,ans=ans+c[i];
			}	
		}

		if(w>n/2){
			for(int i=1;i<=n;i++)
				if(a[i]>=b[i])
					if(a[i]>=c[i])
						lop[++p]=min(a[i]-b[i],a[i]-c[i]);
			sort(lop+1,lop+p+1);
			for(int i=1;i<=w-n/2;i++) ans-=lop[i];
		}
		else if(e>n/2){
			for(int i=1;i<=n;i++)
				if(b[i]>=a[i])
					if(b[i]>=c[i])
						lop[++p]=min(b[i]-a[i],b[i]-c[i]);
			sort(lop+1,lop+p+1);
			for(int i=1;i<=e-n/2;i++) ans-=lop[i];
		}
		else if(r>n/2){
			for(int i=1;i<=n;i++)
				if(c[i]>=a[i])
					if(c[i]>=b[i])
						lop[++p]=min(c[i]-b[i],c[i]-a[i]);
			sort(lop+1,lop+p+1);
			for(int i=1;i<=r-n/2;i++) ans-=lop[i];
		}

		cout<<ans<<endl;
	}
	return 0;
}
