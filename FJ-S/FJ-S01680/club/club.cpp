#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[t];
	for(int i = 0;i<t;i++){
		int n = 0,L = 0;
		ans[i] = 0;
	    cin>>n;
		int n2 = n/2;
		int s1[n2][3],s[n2][3];
		int a[n][3];
	    int a1[n][3];
	    for(int I = 0;I<n;I++){
	    	for(int j = 0;j<3;j++){
	    	cin>>a[I][j];
	    	a1[I][j] = a[I][j];
			}
		}
		for(int I = 0;I<3;I++){
			for(int l = 0;l<n/2;l++){
	    	for(int j = 0;j<n;j++){
	    		L = 0;
	    	if(a[j][I]<a[j+1][I]){
	    		L = j+1;
			}
			s[l][L] = 0;
			s1[l][I] = 	a[L][I];
			s[l][L] = 1;
	    	a[L][I] = 0;
	    	
			}
		}	
		}
		for(int I = 0;I<n;I++){
			int y = 0;
	    	for(int j = 0;j<3;j++){
	    	if(s[I][j] == 1){
	    		y++;	
			}
		}
			if(y == 3){
				for(int q = 0;q<3;q++){
				if(a1[I][q]>a1[I][q+1]){
					ans[i] += a1[I][q];
				} else {
					ans[i] += a1[I][q+1];
				}	
				}
			} else{
				for(int J = 0;J<3;J++){
	    	if(s[I][J] == 1){
	    		ans[i] += s1[I][J];
			}
		}
			}
			}
		}
	
	for(int i = 0;i<t;i++){
		cout<<ans[i];
	}
	return 0;
}
