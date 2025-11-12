#include <iostream>
using namespace std;
int a[500010];
int sk[500010];
int top; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool pa=true,pb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			pa=false;
		if(a[i]>1)
			pb=false;
	}
	if(pa){
		cout<<n/2;
	}
	else if(pb){
		int res=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)
					res++;
				else{
					if(i<n){
						if(a[i+1]==1){
							res++;
							i++;
						}
					}
				}
			}
		}
		else{
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					res++;
		}
		cout<<res;
	}
	else{
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				res++;
				top=0;
			}
			else{
				if(top!=0){
					int tmp=a[i];
					bool find=false;
					for(int j=top-1;j>=0;j--){
						if((tmp^sk[j])==k){
							res++;
							top=0;
							find=true;
							break;
						}
						tmp^=sk[j];
					}
					if(!find){
						sk[top]=a[i];
						top++;
					}
				}
				else{
					sk[top]=a[i];
					top++;
				}
			}
		}
		cout<<res;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
