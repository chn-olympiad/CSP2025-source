#include<bits/stdc++.h>
using namespace std;

long long  n,k,cnt;
int a[5533],s[5555][5555];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i][i]=a[i];
	
			for(int h=i+1;h<=n;h++) {
				s[i][h]=s[i][h-1]^a[h];
			}
			 
		}
	int l=0,r=0;
	for(int i=1;i<=n;i++){
	
	
			for(int h=i+1;h<=n;h++) {
			if(s[i][h]==k&&(i>r||h<l)){
				cnt++;
				l=i,r=h;
			}
					
				}

			}
			
		
	cout<<cnt;
	return 0;
}
