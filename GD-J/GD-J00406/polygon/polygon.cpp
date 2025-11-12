#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool r[100000];
int sum=0;
int n;
int m=3;
int fun(int k,int gd,int maxl,int last){
	if(k==m+1){
		
		if(gd>(maxl*2)){
			if(m==3){
				if((gd-maxl)<maxl){
					return 0;
				}
			}
			sum++;
		}
		return 0;
	}
	for(int i=last;i<=n;i++){
		if(!r[i]){
			r[i]=true;
		    gd+=a[i];
		    if(a[i]>maxl){
			    maxl=a[i];
		    }
		    fun(k+1,gd,maxl,i);
		    r[i]=false;
		    gd-=a[i];
		}
		
	}
	return 0;
}
int main(){
	memset(a,0,sizeof(a));
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if((a[1]+a[2])>a[3]&&(a[2]+a[3])>a[1]&&(a[1]+a[3])>a[2])
		return 0;
	}
	for(int i=3;i<=n;i++){
		fun(1,0,0,1);
		m++;
	}
	cout<<(sum%998)%244%353;
} 


