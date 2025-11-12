#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,k;
int a[N];
bool v[N],flag,flag1,flag2;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag1=1;
			if(a[i]!=0){
				flag=1;
			}
		}
	} 
	if(!flag){
		if(m!=1){
			if(m!=0){
				cout<<0;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}			
		}
				
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		
		else{
			if(!flag1){
				cout<<n/2;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						ans++;
					}
				} 
				for(int i=1;i<=n;i++){
					if(a[i]==1 && a[i+1]==1){
						ans++;
						i++;
					}
				}
				cout<<ans;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=1;j<=i;j++){
			k^=a[j];
			if(v[j]){
				flag2=1;
			}
		}
		if((!flag2) && k==m){
			ans++;
		}
		flag2=0;
		for(int j=2;(j+i-1)<=n;j++){
			k^=a[j-1];
			k^=a[j+i-1];
			for(int l=j;l<=(j+i-1);l++){
				if(v[l]){
					j=l;
					flag2=1;
					break;
				}
			}
			if(flag2){
				flag2=0;
				continue;
			}
			if(k==m){
				ans++;
				for(int l=j;l<=(j+i-1);l++){
					v[l]=1;
				}
				j=(j+i-1);
			}			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
