#include<bits/stdc++.h>
using namespace std;
long long n,k,aa,bb,sum=1;
long long a[500005],b[500005];
bool p=true;
struct pi{
	int fir;
	int sec;	
}f[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(long long i=1;i<=n;i++){
		aa=a[i];
		if(aa==k){
			b[i]=i;
		}
		else{
			for(long long j=i+1;j<=n;j++){
		    	bb=aa^a[j];
		    	if(bb==k){
		    		b[i]=j;
		    		break;
				} 
				else{
					aa=bb;
				}
			}
			if(bb!=k){
				b[i]=0;
			}
		}
		bb=0;
		aa=0;
	}
	for(long long i=1;i<=n;i++){
		if(b[i]!=0){
		//	cout<<b[i]<<endl;
			for(long long j=1;j<=sum;j++){
				if(b[i]<=f[j].sec&&f[j].sec!=0&&i>=f[j].fir&&f[j].fir!=0){
					p=false;
					break;
				}
			}
			if(p==true){
			//cout<<b[i]<<" jinru "<<endl;
				f[sum].sec=b[i];
				f[sum].fir=i;
				sum++;
			}
			p=true;
		}
	}
	cout<<sum-1;
	return 0;
}
