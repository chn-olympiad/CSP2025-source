#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,jm,ans=0,j1=0,j2=0,j3=0;
const int a[i][j];
int main(){
    freopen("club.cpp","r",stdin);
    freopen("club.cpp","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n>>a[i][j];
    for(int i=1;i<=n;i++){
		for(int j=1;j<3;j++){
			if((a[i][j]>a[i][j+1])&&j=1)
				jm=a[i][j];
				continue;
			else if(a[i][j]>a[i][j+1])
				jm=a[i][j];		
			else
				jm=a[i][j+1];
			}
		if(jm==a[i][1]){	
			j1+=1;
		else if(jm==a[i][2])	
			j2+=1;
		else 	
			j3+=1;
			}
		if(jm==a[i][1]&&j1<n/2){
			ans+=jm;
			j1+=1;
			}
		else if(jm==a[i][2]&&j2<n/2){
			ans+=jm;
			j2+=1;
			}
		else if(jm==a[i][3]&&j3<n/2){
			ans+=jm;
			j3+=1;
			}
		else if((j1>=n/2)&&(j2>=n/2)){
			jm=a[i][3];
			ans+=jm;
			j3+=1;
			}
		else if((j1>=n/2)&&(j3>=n/2)){
			jm=a[i][2];
			ans+=jm;
			j2+=1;
			}
		else if((j2>=n/2)&&(j3>=n/2)){
			jm=a[i][1];
			ans+=jm;
			j1+=1;
			}		
		else if(j1>=n/2){
			if((a[i][2]>a[i][3])&&(j2<n/2))
				jm=a[i][2];
				ans+=jm;
				j2+=1;
			else
				jm=a[i][3];
				ans+=jm;
				j3+=1;
			}
		else if(j2>=n/2){
			if((a[i][1]>a[i][3])&&(j1<n/2))
				jm=a[i][1];
				ans+=jm;
				j1+=1;
			else
				jm=a[i][3];
				ans+=jm;
				j3+=1;
			}
		else if(j3>=n/2){
			if((a[i][1]>a[i][2])&&(j1<n/2))
				jm=a[i][1];
				ans+=jm;
				j1+=1;
			else
				jm=a[i][2];
				ans+=jm;
				j2+=1;
			}		
		}
		cout<<ans<<endl;    
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
