#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    	int ans=0;
		int j[3]={0,0,0};
		int n;
		cin>>n;
		int b;
		int s[3];
		int x[n][3];
		for(int i=0;i<n;i++){
			b=0;
			int tag=1,flag=2;
			cin>>s[0]>>s[1]>>s[2];
			if(s[1]>s[0]){
				b=1;
				tag=0;
			}
			if(s[2]>s[b]){
				flag=b;
				b=2;
			}
			if(s[tag]>s[flag]){
				swap(tag,flag);
			}
			ans+=s[b];
			x[j[b]++][b]=s[b]-s[flag];
			
		}
		int f=-1;
		if(j[0]>n/2){
			f=0;
		}
		if(j[1]>n/2){
			f=1;
		}
		if(j[2]>n/2){
			f=2;
		}
		if(f==-1){
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<j[f]-n/2;i++){
			int m=i;
			for(int k=i;k<j[f];k++){
				if(x[k][f]<x[m][f]){
					m=k;
				}
			}
			ans-=x[m][f];
			swap(x[i][f],x[m][f]);
			
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
} 
