#include<bits/stdc++.h>
using namespace std;
//xor is ^
int n,ans,k,s[500005],t[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n<=1000){
		int sum=0;
		for(int l=1;l<=n;l++){
			sum=0;
			for(int i=1;i<=n-l+1;i++){
				int nowsum=0,flag=0;
				for(int j=i;j<=i+l-1;j++){
					if(t[j]==1){
					    flag=1;
					    break;
					}
					nowsum^=s[j];
				}
				if(flag==1){
				    //flag=0;
					continue;
				} 
				sum=nowsum;
				
				if(sum==k){
				    ans++;
				    //cout<<i<<endl;
				    for(int j=i;j<=i+l-1;j++){
				    	t[j]=1;
					}
				}
			}
		}
		cout<<ans;
	}else{
		int sum=0,flag=0;
		for(int l=1;l<=n;l++){
			int be=0,beflag=0;
			sum=0;
			flag=0;
			for(int i=1;i<=n;i++){
				if(t[i]==1){
					be=0;
				}else be++;
				if(be>=l){
					be=i-l+1;
					beflag=1;
					break;
				}
			}
			if(beflag==0) break;
			
			for(int i=be-1;i<=be+l-2;i++){
				sum^=s[i];
			}
			//cout<<"cszt:"<<be<<"  "<<sum<<endl;
			for(int i=be;i<=n-l+1;i++){
				
				if(t[i+l-1]==1){
					flag=1;
					i=i+l;
					sum=0;
					continue;
				}
				if(i!=1) sum&=(-s[i-1]-1);
				//cout<<"1begin:"<<i<<"   "<<"end:"<<i+l-1<<"   "<<"sum:"<<sum<<"  "<<endl;
				sum^=s[i+l-1];
				//cout<<"2begin:"<<i<<"   "<<"end:"<<i+l-1<<"   "<<"sum:"<<sum<<endl;
				if(sum==k){
				    ans++;
					for(int j=i;j<=i+l-1;j++){
						t[j]=1;
					}
					sum=0;
					i=i+l;
					flag=1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
/*
4 2
2 1 0 3
*/
