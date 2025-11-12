#include<iostream>
using namespace std;
int main(){
    freopen("seat","r",stdin);
    freopen("seat","w",stdout);
    int n,m,a[101],b[101];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int h,k=0,t=1;
    h=1;
    k+=a[1];
    if(n*m==1) cout<<n<<" "<<m;
    for(int i=1;i<=n*m;i++){
    	for(int j=1;j<=n*m;j++){
    		b[i]=a[i];
    		if(a[i]<=a[i+1]){
    			a[i]=a[i+1];
    			a[i+1]=b[i];
			}
		}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(h%2==1){
    			if(a[t]==k) cout<<i<<" "<<j;
			}
			else{
				if(a[t]==k) cout<<i<<" "<<m-j+1;
			}t++;
		}h++;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
