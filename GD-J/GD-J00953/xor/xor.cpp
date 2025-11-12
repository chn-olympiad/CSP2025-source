#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int sum=0;
int a[N],b[N];
int t=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k ){
			if(i==1 || i==n) b[i]=-1;
			else{
				b[i]=-1,t++,a[i]=-1;
			} 
			sum++;
			continue;
		}
		t++;
		if(a[i]!=-1)
			b[i]=a[i+1]^a[i];
		else b[i]=a[i+1];
	}
	
	while(t>0){
		for(int i=1;i<=t-1;i++){
			if(b[i]==-1 || b[i+1]==-1){
				continue;
			}
			int c=b[i+1]^b[i];
			if(b[i]==k){
				sum++;
				b[i]=c;
				continue;
			}
			
			if(c==k){
				b[i]=-1;
				sum++;
				continue;
			}
			b[i]=c;
		}
		t--;
	}
		
	
	cout<<sum;
	return 0;
}

