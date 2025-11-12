#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
int n;
int a1[N],a2[N],a3[N],dp[N];
int m;
int ans;
int o;
signed main()
{
		freopen("club.in","r",stdin);
	   	freopen("club.out","w",stdout);
	   	cin>>n;
	   
	   	for(int i=1;i<=n;i++){
	   		cin>>m;
	   		ans=0;
	   		int p=m/2;
	   		int n1=0,n2=0,n3=0;
	   		
	   		for(int j=1;j<=m;j++){
	   			cin>>a1[j]>>a2[j]>>a3[j];
	   			if((a1[j]>a2[j])&&(a1[j]>a3[j])){
	   				n1++;
	   				ans+=a1[j];
	   				//cout<<ans<<" "<<j<<endl;
				   }
				if((a2[j]>a1[j])&&(a2[j]>a3[j])){
	   				n2++;
	   				ans+=a2[j];
	   				//cout<<ans<<" "<<j<<endl;
				   }
				if((a3[j]>a2[j])&&(a3[j]>a1[j])){
	   				n3++;
	   				ans+=a3[j];
	   				//cout<<ans<<" "<<j<<endl;
				   }
			   	}
			   	sort(a1+1,a1+1+m);
			   	sort(a2+1,a2+1+m);
			   	sort(a3+1,a3+1+m);
			   	for(int j=1;j<=p;j++){
			   		if(m==2)
			   			if(a1[j]==0&&a2[j]==0){
			   				if(j==2){
			   					ans=ans-a3[j-1]+max(a1[j-1],a2[j-1]);
			   					continue;
							   }
							else{
								ans=ans-a3[j+1]+max(a1[j+1],a2[j+1]);
								break;
							}
									
						}else if(a2[j]==0&&a3[j]==0){
							if(j==2){
								ans=ans-a1[j-1]+max(a3[j-1],a2[j-1]);
								continue;
							}
			   					
							else{
								ans=ans-a1[j+1]+max(a3[j+1],a2[j+1]);
								break;
							}
								
						}else if(a1[j]==0&&a3[j]==0){
							if(j==2){
								ans=ans-a2[j-1]+max(a1[j-1],a3[j-1]);
								continue;
							}
			   					
							else{
								ans=ans-a3[j+1]+max(a1[j+1],a3[j+1]);
								break;
							}
								
						}
			   		while(n1>p){
			   			ans-=a1[j];
			   			n1--;
					   }
			   		while(n2>p){
			   			ans-=a2[j];
			   			n2--;
					   }
					while(n3>p){
			   			ans-=a3[j];
			   			n3--;
			   			//cout<<ans<<endl;
					   }	
				   }
			cout<<ans<<endl;
	   }
	   return 0;
	   
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0


Ren5Jie4Di4Ling5%


*/

