#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0,ans1=0,flag[4]={0},ha[n][4];
		memset(ha,0,sizeof(ha));
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			ha[i+1][1]=a;
			ha[i+1][2]=b;
			ha[i+1][3]=c;
			if((flag[1]<n/2)&&(max(max(a,b),c)==a)){
				ans+=a;
				flag[1]++;			
			}else if((flag[2]<n/2)&&(max(b,c)==b)){
				ans+=b;	
				flag[2]++;		
			}else{
				ans+=c;
				flag[3]++;
			}
		}
		memset(flag,0,sizeof(flag));
		memset(ha,0,sizeof(ha));
		for(int i=n;i>=1;i--){
			if((flag[1]<n/2)&&(max(ha[i][1],max(ha[i][2],ha[i][3]))==ha[i][1])){
				ans1+=ha[i][1];
				flag[1]++;			
			}else if((flag[2]<n/2)&&(max(ha[i][2],ha[i][3])==ha[i][2])){
				ans1+=ha[i][2];	
				flag[2]++;		
			}else{
				ans1+=ha[i][3];
				flag[3]++;
			}
		}
		cout<<max(ans,ans1)<<endl;	
	}
	return 0;
}
 
