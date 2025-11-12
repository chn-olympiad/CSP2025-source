#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int t[n],a[n][3],max,num[3]={0,0,0},w[3][n],ans=0;
		
		for(int i=0;i<n;i++){
			cin>>t[0]>>t[1]>>t[2];
			max=0;
			for(int j=1;j<3;j++){
				if(t[max]<t[j]){
					max=j;			
				}
			}
			a[num[max]++][max]=i;//cout<<"OK"<<endl;
			sort(t,t+3);
			w[max][num[max]-1]=t[2]-t[1];
			ans+=t[2];
		}
		max=-1;
		for(int i=0;i<3;i++){
			if(num[i]>n/2)
			{
				max=i;
			}
		}
		if(max==-1){
			cout<<ans<<endl;
			continue;
		}
		
		else{
			for(int i=0;i<num[max];i++)
			{
				t[i]=w[max][i];
			}
			sort(t,t+num[max]);
			int i=0;
			while(num[max]>n/2)
			{
				ans-=t[i];
				i++;
				num[max]--;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
