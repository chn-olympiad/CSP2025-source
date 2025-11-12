#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
    int n,k,e=0,max=0;
    cin>>n>>k;
    int a[n+1];
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int j=1;j<=n;j++){
				if(j==1){
					x=x;
				}else{
					x=x|a[j];
				}
				if(x==k){
					e=j-i+1;
				}
				if(max<e){
					max=e;
				}
			}
		}
		cout<<max+1;
	fclose("stdin");
	fclose('stdout');
		return 0;
}
