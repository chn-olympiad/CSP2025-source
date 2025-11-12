#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k,nem[5000005],ans_x=0;
	bool nem1[5000005]={};
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>nem[i];
	for(int i=1;i<=n;i++){
		int a[n+5];
		for(int p=0;p<n-i+1;p++){
			int ans=nem[p];
			for(int q=0;q<i;q++){
				if(nem1[p+q]){
					p=p+q;
					ans=-1;
					break;
				}
				else if(q!=0){
					ans=ans^nem[p+q];
				}
			}
			a[p]=ans;
		}
		for(int p=0;p<n-i+1;p++){
			if(a[p]==k){
				ans_x++;
				for(int q=0;q<i;q++) nem1[p+q]=1;
			}
		}
	}
	cout<<ans_x;
	return 0; 
} 
