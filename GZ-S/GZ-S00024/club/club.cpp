//GZ-S00024  何彦辰 遵义市第四中学
#include <bits/stdc++.h>
using namespace std;
long long int t,n,a1[100000],a2[100000],a3[100000],i1,i2,i3,y[100000],x,j,k;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a1[i]>>a2[i]>>a3[i];
    	if(a1[i]>a2[i]){
    		if(a1[i]>a3[i]){
    			i1++;
    			x+=a1[i];
    			if(a2[i]<a3[i]){
    				y[i]=a1[i]-a3[i];
				}
				else{
					y[i]=a1[i]-a2[i];
				}
			}
			else{
				i3++;
				x+=a3[i];
				y[i]=a3[i]-a1[i];
			}
		}

		else{
			if(a2[i]>a3[i]){
    			i2 ++;
    			x+=a2[i];
    			if(a1[i]<a3[i]){
    				y[i]=a2[i]-a3[i];
				}
				else{
					y[i]=a2[i]-a1[i];
				}
			}
			else{
				i3++;
				x+=a3[i];
				y[i]=a3[i]-a2[i];
			}
		}
	}
	if(i1>n/2){
		for(int i=1;i<=i1-n/2;i++){
			for(int k=1;k<n;k++){
			if(y[i]<y[i+1]){
			   j=i;
			}
			else{
				j=i+1;
			}
		}
		x-=y[j];
		}
	}
	if(i2>n/2){
		for(int i=1;i<=i2-n/2;i++){
			for(int k=1;k<n;k++){
			if(y[i]<y[i+1]){
			   j=i;
			}
			else{
				j=i+1;
			}
		}
		x-=y[j];
		}
	}
	if(i3>n/2){
		for(int i=1;i<=i3-n/2;i++){
			for(int k=1;k<n;k++){
			if(y[i]<y[i+1]){
			   j=i;
			}
			else{
				j=i+1;
			}
		}
		x-=y[j];
		}
	}
    	cout<<x<<endl;
    	i1=0; i2=0; i3=0; x=0; j=0; k=0;
	}
	fclose(stdin);
	fclose(stdout);
}

