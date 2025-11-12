#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1010];
int m[110][110];
bool b[10000];
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	if(n<=100){
		for(int i=1;i<=n;i++){
		cin>>a[i];
	    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				m[i][j]=a[i];
			}
			else{
				m[i][j]=a[i]^m[i-1][j];
	
			}
			flag=false;
			if(m[i][j]==k){
				int v=i;
				while(v>=j){
					if(b[v]==true){
						flag=true;
					}
					v--;
				}
				if(flag==false){
				    ans++;
			       int l=i;
			       while(l>=j){
			  	    b[l]=true;
			  	    l--;
			        }
				}
			  
			}
		}
	}
	cout<<ans;
	}
	else{
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    if(a[i]==k)
			ans++;
	  }
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
