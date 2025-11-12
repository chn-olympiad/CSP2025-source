#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int part1[N],part2[N],part3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++){
			cin>>part1[i]>>part2[i]>>part3[i];
		}
		int sum1=0,sum2=0,sum3=0;
		sort(part1+1,part1+n+1);
		sort(part2+1,part2+n+1);
		sort(part3+1,part3+n+1);
		
		for(int i=n;i>=1;i--){
			int a=part1[i],b=part2[i],c=part3[i];
			
			int mx=max(a,b);
			mx=max(mx,c);
			if(mx==a){
				if(sum1+1<k){
					ans+=mx;
					sum1++;
				}
				else{
					mx=max(b,c);
					if(mx==b){
						if(sum2+1<k){
							ans+=mx;
							sum2++;
						}
						else{
							ans+=c;
							sum3++;
						}
					}
				}
			}
			else if(mx==b){
				if(sum2+1<k){
					ans+=mx;
					sum2++;
				}
				else{
					mx=max(a,c);
					if(mx==a){
						if(sum1+1<k){
							ans+=mx;
							sum1++;
						}
						else{
							ans+=c;
							sum3++;
						}
					}
				}
			}
			else{
				if(sum3+1<k){
					ans+=mx;
					sum3++;
				}
				else{
					mx=max(a,b);
					if(mx==a){
						if(sum1+1<k){
							ans+=mx;
							sum1++;
						}
						else{
							ans+=b;
							sum2++;
						}
					}
				}
			}
			
		}
		cout<<ans<<endl;
		
		/*
		for(int i=n;i>=1;i--){
			cout<<part1[i]<<" ";
		}
		cout<<endl;
		for(int i=n;i>=1;i--){
			cout<<part2[i]<<" ";
		}
		cout<<endl;
		for(int i=n;i>=1;i--){
			cout<<part3[i]<<" ";
		}
		cout<<endl;
		*/
	}
	return 0;
}
