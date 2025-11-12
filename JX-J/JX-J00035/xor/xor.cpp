#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],h=1,cnt=0;
long long f[500010],x[500010],y[500010];
bool d[500010];
int safe(int l,int r){
	int c=0;
	for(int i=l;i<=r;i++){
		c&=a[i];
		}
		return c;
	}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}	
		if(k==0){
		cout<<0;
		return 0;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[h]=safe(a[i],a[j]);
				x[h]=i;
				y[h]=j;
				h++;
				
				}
			}
			for(int i=1;i<=h;i++){
				if(f[i]==k){
					cnt++;
					for(int j=x[i];j<=y[i];j++){
						if(d[i]==true){
						cnt--; 
						break;	
							}
						else d[i]=true;
						}
					}
				}			
			cout<<cnt;
			return 0;
	}
