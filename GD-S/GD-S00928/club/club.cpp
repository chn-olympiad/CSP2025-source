#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,avis[N],bvis[N],cvis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int alon=0,blon=0,clon=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
			if(a>=max(b,c))avis[++alon]=a-max(b,c);
			else if(b>=max(a,c))bvis[++blon]=b-max(a,c);
			else cvis[++clon]=c-max(b,a);
		}
		if(alon>n/2){
			sort(avis+1,avis+1+alon);
			for(int i=1;i<=alon-n/2;i++)ans-=avis[i];
		}
		if(blon>n/2){
			sort(bvis+1,bvis+1+blon);
			for(int i=1;i<=blon-n/2;i++)ans-=bvis[i];
		}
		if(clon>n/2){
			sort(cvis+1,cvis+1+clon);
			for(int i=1;i<=clon-n/2;i++)ans-=cvis[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
