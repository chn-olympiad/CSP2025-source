#include<bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int ma[N],mi[N],sj[N],mmm[N];
void max(int a,int b,int c,int i){
	if(a<b)swap(a,b);
	if(a<c)swap(a,c);
	ma[i]=a;
	mmm[i]=a;
	if(b<c)swap(b,c);
	mi[i]=b;
}
void px(int n){
	for(int i=1;i<=n;i++){
		sj[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mmm[j]<mmm[j+1]){
				swap(sj[j],sj[j+1]);
				swap(mmm[j],mmm[j+1]);
			}
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int aa=1;aa<=t;aa++){
		int n,a[N],b[N],c[N];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		
		for(int i=1;i<=n;i++){
			max(a[i],b[i],c[i],i);
		}
		px(n);
		int a1=0,b1=0,c1=0,ans=0;
		for(int j=1;j<=n;j++){
			int i=sj[j];
			if(ma[i]==a[i]){
				if(a1<n/2){
					ans+=ma[i];
					a1++;
				}
				else if(mi[i]==b[i]){
					if(b1<n/2){
						ans+=mi[i];
						b1++;
					}
					else{
						ans+=c[i];
						c1++;
					}
				}
				else if(mi[i]==c[i]){
					if(c1<n/2){
						ans+=mi[i];
						c1++;
					}
					else{
						ans+=b[i];
						b1++;
					}	
				}
			}
			else if(ma[i]==b[i]){
				if(b1<n/2){
					ans+=ma[i];
					b1++;
				}
				else if(mi[i]==a[i]){
					if(a1<n/2){
						ans+=mi[i];
						a1++;
					}
					else{
						ans+=c[i];
						c1++;
					}
				}
				else if(mi[i]==c[i]){
					if(c1<n/2){
						ans+=mi[i];
						c1++;
					}
					else{
						ans+=a[i];
						a1++;
					}	
				}
			}	
			else if(ma[i]==c[i]){
				if(c1<n/2){
					ans+=ma[i];
					c1++;
				}
				else if(mi[i]==b[i]){
					if(b1<n/2){
						ans+=mi[i];
						b1++;
					}
					else{
						ans+=a[i];
						c1++;
					}
				}
				else if(mi[i]==a[i]){
					if(a1<n/2){
						ans+=mi[i];
						a1++;
					}
					else{
						ans+=b[i];
						b1++;
					}	
				}
			}
		}
		cout<<ans<<endl;
	}
}
