#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,o,p;
	cin>>n>>m;
	int a[n][m],s[n*m],k;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	int q=n*m;
	sort(s+1,s+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(s[q]!=k){
					s[q]=a[j][i];
					q--;	
				}
				else{
					if(cnt==1){
						o=i,p=j;
					}
					cnt--;
				} 
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(s[q]!=k){
					s[q]=a[j][i];
					q--;	
				}
				else{
					if(cnt==1){
						o=i,p=j;
					}
					cnt--;
				} 
			}
		}
	}
	cout<<o<<' '<<p;
	return 0;
}
