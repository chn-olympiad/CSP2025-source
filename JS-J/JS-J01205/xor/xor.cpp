#include<bits/stdc++.h>
using namespace std;
int n,k,r[500005],ans=0,j=1,flo=2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>r[i];
		if(r[i]==k){
			ans++;
			r[i]=-1;
		}
	}
	while(j>0){
		j=0;
		bool j0=1;
		for(int fir=0;fir<(n+1-flo);fir++){
			for(int i=0;i<flo;i++){
				if(r[fir+i]==-1){
					j0=0;
					break;
				}
				if(i!=0)r[fir]=r[fir]^r[fir+i];
			}
			if(r[fir]==k){
				for(int i1=0;i1<flo;i1++){
					r[fir+i1]=-1;
				}
			ans++;
			}
			else if(j0)j++;
			flo++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
