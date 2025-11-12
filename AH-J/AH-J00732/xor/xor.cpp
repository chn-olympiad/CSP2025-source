#include<iostream>
using namespace std;
int n,k,cnt,f;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=1;
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
	}else if(k==0){//k==0 
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				cnt++;
				i++;
			}else if(a[i]==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
