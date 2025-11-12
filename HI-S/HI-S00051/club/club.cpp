#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,jl=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int a1[100010],a2[100010],a3[100010],a=0,b=0,c=0;
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]>a2[j] && a1[j]>a3[j]){
				if(a<n/2){
					a++;
					jl+=a1[j];
				}else{
					if(a2[j]>a3[j]){
						if(b<n/2){
							b++;
							jl+=a2[j];	
						}else{
							c++;
							jl+=a3[j];
						}
					}else if(a2[j]<a3[j]){
						if(c<n/2){
							c++;
							jl+=a3[j];	
						}else{
							b++;
							jl+=a2[j];
						}
					}
				}
			}else if(a2[j]>a1[j] && a2[j]>a3[j]){
				if(b<n/2){
					b++;
					jl+=a2[j];
				}else{
					if(a1[j]>a3[j]){
						if(a<n/2){
							a++;
							jl+=a1[j];	
						}else{
							c++;
							jl+=a3[j];
						}
					}else if(a1[j]<a3[j]){
						if(c<n/2){
							c++;
							jl+=a3[j];	
						}else{
							a++;
							jl+=a1[j];
						}
					}
				}
			}else if(a3[j]>a1[j] && a3[j]>a2[j]){
				if(c<n/2){
					c++;
					jl+=a3[j];
				}else{
					if(a2[j]>a1[j]){
						if(b<n/2){
							b++;
							jl+=a2[j];	
						}else{
							a++;
							jl+=a1[j];
						}
					}else if(a2[j]<a1[j]){
						if(a<n/2){
							a++;
							jl+=a1[j];	
						}else{
							b++;
							jl+=a2[j];
						}
					}
				}
			}else if(a1[j]==a2[j]){
				if(a>=n/2 && b>=n/2){
					c++;
					jl+=a3[j];
				}else if(a>=n/2 && c>=n/2){
					b++;
					jl+=a2[j];
				}else if(b>=n/2 && c>=n/2){
					a++;
					jl+=a1[j];
				}
			}
		}
		if(i==1){
			cout<<jl;
		}else{
			cout<<"\n"<<jl;
		}	
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return 0;
} 
