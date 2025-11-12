#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],mx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2;	
		}
		else if(a[1]==k){
			cout<<1;
		}
		else if(a[2]==k){
			cout<<1;
		}
		else if(a[1]^a[2]==k){
			cout<<1;
		}
		else cout<<0;
		return 0;
	} 
	if(n==3){
		if(a[1]==k&&a[2]==k&&a[3]==k){
			cout<<3;	
		}
		else if(a[1]==k&&a[2]==k){
			cout<<2;	
		}
		else if(a[1]==k&&a[3]==k){
			cout<<2;	
		}
		else if(a[3]==k&&a[2]==k){
			cout<<2;	
		}
		else if(a[1]^a[2]==k&&a[3]==k){
			cout<<2;
		}	
		else if(a[1]^a[3]==k&&a[2]==k){
			cout<<2;
		}
		else if(a[3]^a[2]==k&&a[1]==k){
			cout<<2;
		}	
		else if(a[1]^a[2]==k){
			cout<<1;
		}
		else if(a[1]^a[2]==k){
			cout<<1;
		}
		else if(a[1]^a[2]==k){
			cout<<1;
		}
		else if(a[1]==k){
			cout<<1;
		}
		else if(a[2]==k){
			cout<<1;
		}
		else if(a[3]==k){
			cout<<1;
		}
		else cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;){
		long long s=a[i];
		int i2=i;
		while(s!=k){
			int f=0;
			for(int j=i+1;;j++){
				if(j>n){
					cout<<mx;
					return 0;
				}
				i2++;
				if(a[j]==k){
					f=1;
					break;
				}
				s^=a[j];
				if(s==k){
					f=1;
					break;	
				}
				
			}
			if(f==1)break;
		}
		i=i2+1;
		mx++;
		if(i2>n)break;
	}
	cout<<mx;
	return 0;
}
