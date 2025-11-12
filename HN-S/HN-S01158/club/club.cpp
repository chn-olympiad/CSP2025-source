#include<bits/stdc++.h>
using namespace std;
int t,n,x[1005],y[1005],z[1005],sum,ans,rsx,rsy,rsz;
int maxx(int a,int b,int c){
	return max(a,max(b,c));
}
void dfs(int a,int b){//第a个学生，对第b个club的好感
	if(a>n){
		if(ans==0){
			ans=sum;
				return;
			}
			else{
				ans=max(ans,sum);
				return;
			}
			
		}
	else{
		if(b==1 and rsx<n/2){
			rsx++;
			sum+=x[a];
			dfs(a+1,1); 
			dfs(a+1,2); 
			dfs(a+1,3);
			sum-=x[a]; 
			rsx--;
	//		cout<<sum<<" ";
		}
		if(b==2 and rsy<n/2){
			rsy++;
			sum+=y[a];
			dfs(a+1,1); 
			dfs(a+1,2); 
			dfs(a+1,3);
			sum-=y[a]; 
			rsy--;
		}	
		if(b==3 and rsz<n/2){
			rsz++;
			sum+=z[a];
			dfs(a+1,1); 
			dfs(a+1,2); 
			dfs(a+1,3); 
			sum-=z[a];
//			cout<<sum<<" ";
			rsz--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
			sum=0;ans=0;rsx=0;rsy=0;rsz=0;
				cin>>n;
				for(int j=1;j<=n;j++){
				cin>>x[j]>>y[j]>>z[j];
				}
				for(int j=1;j<=3;j++){
				dfs(1,j);
				}
				cout<<ans<<endl;
			
			fclose(stdin);
			fclose(stdout);
			return 0;
		
	} 
}

