#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];

int main(){
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	cin.tie(NULL);
	
	int n, k;
	cin>>n>>k;
	for(int i = 0;i<n;i++) cin>>a[i];
	int ans=0;
	for(int i = 0;i<n;i++) if(a[i]==k) ans++, b[i]=1;
	
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			
			//相交 
			if(b[i]||b[j]){
				i++;
				break;
			}
			
			//不相交 
			if(i!=j){
				
				//int x=a[i], l=i, r=j;
				//for(;l<=r;l++) x=x^a[l];
				
				int x=a[i], l=i, r=j;
				for(l = i+1;l<=r;l++) x=x^a[l];
				
				if(x==k){
					ans++;
					//cout<<"^= "<<i<<' '<<j<<'\n';
					for(int c = i;c<=j;c++) b[c]=1;
				}
				//else cout<<"?^= "<<i<<' '<<j<<'\n';
			}
			
		}
	}
	
	cout<<ans;
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
