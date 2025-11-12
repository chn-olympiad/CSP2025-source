#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],b[500001],bj[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b[1]==a[1];
		}else{
			 b[i]=(a[i]^a[i-1]);
		}	
	}
	int l=1,r=1,js=0;
	for(int i=1;l<=n;i++){
		if(bj[l]!=1){
					while(1){
				if(b[l]==k){
					js++;
					l=r+1;
				}else if((b[r]^b[l])==k && r!=l){
					js++;
					l=r+1;
				}
				bj[r]=1;
				r++;
				if(r>n){
					break;
				}
				
			}	
		}

		l=i;
		r=l;
	}
	
	cout<<js;
	
	fclose(stdin);
	fclose(stdout);
	return 1;
}

