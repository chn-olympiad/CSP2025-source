#include<bits/stdc++.h>
using namespace std;
int a[101010],b[101010],c[101010],ans[101010];
bool cmp(int x,int y){
	return x>y;
}
int asd,zxc,sum;
int t,n,qwe,he;
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin >> t;
	for(int j=1;j<=t;j++){
		cin >> n;
		int iop=0,jkl=0,bnm=0;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(c[i]==0){
					if(a[i]==0){
						if(jkl<n/2){
							he=he+b[i];
							jkl++;
						}else if(b[i]>=b[i-2]||b[i]>=b[i-1]||b[i]>=b[i-3]){
								he=he+b[i]-b[i-2];
							}
				    	
					}else{
						if(a[i]+b[i-1]>=a[i-1]+b[i]||a[i]+b[i-2]>=a[i-2]+b[i]){
							if(iop<n/2){
								iop++;he=he+a[i]+b[i-1]-a[i-1]-b[i];
							}
							
						} 
						else if(a[i]+b[i-1]<=a[i-1]+b[i]||a[i]+b[i-2]<=a[i-2]+b[i]){
							if(jkl<n/2)
							jkl++;he=he+a[i]+b[i-1];
						}
					}
					 
			    
				
			}
			else{
				if(a[i]>=b[i]&&a[i]>=c[i]&&b[i]>=c[i]){
				
				if(qwe<n/2){
						qwe++;he+=a[i];
				}else{
						asd++;he+=b[i];
				}
				}else if(a[i]>=b[i]&&a[i]>=c[i]&&b[i]<=c[i]){
					
					if(qwe<n/2){
						qwe++;he+=a[i];
					}else{
						zxc++;he+=c[i];
					}
				}else if(b[i]>=a[i]&&b[i]>=c[i]&&a[i]>=c[i]){
					
					if(asd<n/2){
						asd++;he+=b[i];
					}else{
						qwe++;he+=a[i];
					}
				}else if(b[i]>=a[i]&&b[i]>=c[i]&&a[i]<=c[i]){
					
					if(asd<n/2){
						asd++;he+=b[i];
					}else{
						zxc++;he+=c[i];
					}
				}else if(c[i]>=a[i]&&c[i]>=b[i]&&a[i]>=b[i]){
					
					if(zxc<=n/2){
						zxc++;he+=c[i];
					}else{
						qwe++;he+=a[i];
					}
				}else if(c[i]>=a[i]&&c[i]>=b[i]&&a[i]<=b[i]){
					
					if(zxc<=n/2){
						zxc++;he+=c[i];
					}else{
						asd++;he+=b[i];
					}
				}
			
			}
			
		
	}
		ans[j]=he;
		qwe=0;
		asd=0;
		zxc=0;
		he=0;
			
	}
	for(int i=1;i<=n+1;i++){
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
