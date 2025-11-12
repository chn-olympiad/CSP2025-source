#include<bits/stdc++.h>
using namespace std;
string a[1000005],b[1000005],c,d,ss;
bool f=1;
int n,q,x,xx,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	while(q--){
		ans=0;
		cin>>c>>d;
		ss=c;
		for(int i=0;i<n;i++){
			x=c.size();
			xx=a[i].size();
			if(a[i]==c&&b[i]==d){ans++;continue;}
			for(int j=0;j<=x-xx;j++){
				int s=0;
				for(int k=j;k<=j+xx-1;k++){
					if(c[k]!=a[i][s])f=0;
					s++;
				}
				s=0;
				if(f==1){
					for(int k=j;k<=j+xx-1;k++){
						c[k]=b[i][s++];
					}
					if(c==d) ans+=1;
					c=ss;
				}
				f=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
