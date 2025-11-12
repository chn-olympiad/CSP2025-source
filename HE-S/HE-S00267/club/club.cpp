#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;

int a[N],b[N],c[N],f[N],ap,bp,cp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int res=0;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
			f[i]+=max(a[i],max(b[i],c[i]));	
		}
		for(int i=0;i<n;i++){
			if(f[i]==a[i]&&ap<n/2){
				res+=a[i];
				ap++;
			}else if(f[i]==b[i]&&bp<n/2){
				res+=b[i];
				bp++;
			}else if(f[i]==c[i]&&cp<n/2){
				res+=c[i];
				cp++;
			}else{
				if(ap<n/2){
					res+=a[i];
				}else{
					res+=b[i];
				}
			}
			
		
		}
		cout<<res;
		res=0;
		
	}
	return 0;
}
