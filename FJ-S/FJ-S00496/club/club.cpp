#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005],c[100005];
int h;
int k[100005];
int cnt=0,s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		h=0;
		cnt=0;
		cin>>n;
		int aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				aa++;
				k[i]=1;
				h+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				bb++;
				k[i]=2;
				h+=b[i];
			}else{
				cc++;
				k[i]=3;
				h+=c[i];
			}
		}
		if(max(aa,max(bb,cc))<=n/2){
			cout<<h<<endl;
		}else{
			if(aa>n/2){
				for(int i=1;i<=n;i++){
					if(k[i]==1){
						cnt++;
						s[cnt]=a[i]-max(b[i],c[i]);
					}
				}
				sort(s+1,s+1+cnt);
				for(int i=1;i<=aa-n/2;i++){
					h-=s[i];
				}
			}else if(bb>n/2){
				for(int i=1;i<=n;i++){
					if(k[i]==2){
						cnt++;
						s[cnt]=b[i]-max(a[i],c[i]);
					}
				}
				sort(s+1,s+1+cnt);
				for(int i=1;i<=bb-n/2;i++){
					h-=s[i];
				}
			}else{
				for(int i=1;i<=n;i++){
					if(k[i]==3){
						cnt++;
						s[cnt]=c[i]-max(a[i],b[i]);
					}
				}
				sort(s+1,s+1+cnt);
				for(int i=1;i<=cc-n/2;i++){
					h-=s[i];
				}
			}
			cout<<h<<endl;
		}
	}
	return 0;
} 
