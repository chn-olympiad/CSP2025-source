#include<bits/stdc++.h>
using namespace std;
int bin(int a){
	int k[1005],pop=1;
	memset(k,0,sizeof(k));
	while(a>=2){
		k[pop]=a%2;
		a/=2;
		pop++;
	}
	k[pop]=a;
	int res=0;
	for(int i=pop;i>=1;--i){
		res*=10;
		res+=k[i];
	}
	return res;
}
int yh(int a,int b){
	int c=0;
	if(a==0&&b==0){
		return 1;
	}
	//int k[1005],pop=1;
	//memset(k,0,sizeof(k));
	int flg=0;
	while(a!=0||b!=0){
		if(a%10!=b%10){
			if(flg==0) {
			    c*=10;
			    c++;
			}
			else {
			c+=10;	
			flg=0;
			}
			
			//cout<<"buxt"<<endl;
		}else{
			c*=10;
			if(c==0) flg++;
			//cout<<"xt"<<endl;
		}
		b/=10;
		a/=10;
	}
	return c;
}
int a[1005];
int vis[1005];
int main(){
	//cout<<bin(1)<<" "<<bin(0)<<" "<<bin(3)<<" "<<yh(yh(bin(1),bin(0)),bin(3))<<" "<<bin(2);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    k=bin(k);
    for(int i=1;i<=n;++i){
    	cin>>a[i];
	}
	int res=0;
	int j;
	for(int i=1;i<=n;++i){
	    j=i+1;
	    if(vis[i]==0){
	    if(bin(a[i])==k){
	    	vis[i]++; 
	    	res++;
	    	//cout<<"序列"<<res<<":"<<a[i]<<endl;
		}else{
			int cnt=bin(a[i]);
		    while(j<=n){
	    	    cnt=yh(cnt,bin(a[j]));
	    	    if(cnt==k){
	    	    	res++;
	    	    	//cout<<"序列"<<res<<":";
	    	    	for(int p=j;p>=i;--p){
	    	    		vis[p]=1;
	    	    		//cout<<a[p]<<" ";
					}
					//cout<<endl;
	    	    	break;
				}
				++j;
		    }
		}	
		}
	    
	}
	cout<<res;
	return 0;
}