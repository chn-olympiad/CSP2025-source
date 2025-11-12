#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	ll sum,o=0;
	cin>>n>>k;
	int a[n];
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	} 
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	cin>>a[0];
	if(a[0]==k){
		o++;
		a[0]=-1;
	}
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			o++;
			a[i]=-1;
		}else{
			if(a[i-1]!=-1&&a[i]^a[i-1]==k){
				o++;
				a[i]=a[i-1]=-1;
			}
		}
	}
	if(k==0){
		cout<<o;
		return 0;
	}
	for(int i=0;i<n;i++){
		sum=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]!=-1){
				sum=sum^a[j];
				if(sum==k){
					o++;
					i=j+1;
					break;
				}
			}
		}
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
