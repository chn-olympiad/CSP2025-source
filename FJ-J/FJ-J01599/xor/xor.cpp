#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,ans=0,m=0,ans1,o;
long long a[50010];
bool b[50010];
bool t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	m=ans;
	/*for(int i=2;i<=n-m;i++){
		for(int j=0;j<=n-i;j++){
			ans1=a[j];
			for(int s=j;s<i+j-1;s++){
				ans1=ans1^a[s+1];
				if(b[s]==1||b[s+1]==1){
					t=1;
					break;
				}
			}
			cout<<i<<" "<<ans1<<endl;
			if(ans1==k&&t==0){
				ans++;
				
				for(int s=j;s<=i-2;s++){
					b[s]=1;
					b[s+1]=1;
				}
			}
			t=0;	
		}
	}*/
	for(int i=2;i<=n-m;i++){
		//for(int j=0;j<=n-i;j++){
		ans1=a[0];
		for(int s=0;s<i-1;s++){
			ans1=ans1^a[s+1];
			if(b[s]==1||b[s+1]==1){
				t=1;
				if(b[s]==1) o=s;
				if(b[s+1]==1) o=s+1;
				
			}
				
		}
		if(ans1==k&&t==0){
			ans++;
				
			for(int s=0;s<i-1;s++){
				b[s]=1;
				b[s+1]=1;
			}
		}
		t=0;
		
		
		for(int j=1;j<=n-i+1;j++){
			ans1^=a[j-1];
			ans1^=a[j+i-1];
			if(j-1<o){
				t=1;
			}
			if(b[j+i-1]==1){
				t=1;
				o=j+i-1;
			}
			
			//cout<<i<<" "<<ans1<<endl;
			if(ans1==k&&t==0){
				ans++;
				
				for(int s=j;s<=i-2;s++){
					b[s]=1;
					b[s+1]=1;
				}
			}
			t=0;	
			//cout<<i<<" "<<ans1<<endl;
			
		}
	}
	cout<<ans;
	return 0;
} 
