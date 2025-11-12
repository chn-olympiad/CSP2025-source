#include <bits/stdc++.h>		
using namespace std;
int n,k,sum,cnt;
bool flag=false,folg=false;		
int a[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
									
	for(int i=1;i<105;i++){
		a[i]=k;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			flag=true;
			for(int j=1;j<=n;j++){
				if(a[j]==k){
					continue;
				}
				sum=sum^a[j]; 
				cnt+=1;
			}
			if(sum==k){
				int xo=0;
				for(int j=1;j<=n;j++){
					if(a[j]==k){
						continue;
					}
					if(a[j+1]!=k&&a[j]!=k||a[j-1]!=k&&a[j]!=k){	
						xo+=1;
					}
					
				}
				if(cnt==xo){
					folg=true;
					cout<<cnt/2+1;				
				}	
				break;
			}	
		}	
		
	}
	if(!folg&&flag){
		cout<<1;
	}							
	fclose(stdin);
	fclose(stdout);
	return 0;
} 