#include<iostream>
using namespace std;
int n,k,a[105],s=0,t=0;
bool m=1,m1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) m=0;
		if(a[i]>1) m1=0;
	}
	if(m==1){
		if(k==0){
			cout<<n/2;
			return 0;
		}
		else if(k==1){
			cout<<n;
			return 0;
		}
	}
	else if(m1==1){
		if(k==0){
			for(int i=1;i<=n;i++){
					t=0;
					while(a[i]==1){
						t++;
						i++;
					}
					if(i<=n) s++;
					s+=t/2;
				}
			}
			else{//k=1
				for(int i=1;i<=n;i++){
					if(a[i]==1) s++;
				}
			}
		}	
	cout<<s;
	fclose(stdin);fclose(stdout);
	return 0;
}
 
