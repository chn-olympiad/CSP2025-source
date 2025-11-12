#include<bits/stdc++.h>
using namespace std;
int maxn[100010],maxn2[100010],maxs[100010],maxs2[100010],t1[100010],s1[100010],dan[100010];
struct stu{
	int a1,a2,a3;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,p=0;int m;
	cin>>t;
	for(int j=1;j<=t;j++){
		int ans=0,a1s=0,a2s=0,a3s=0;
		cin>>n;
	if(n==2){
			 m=0;
		for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
			maxn[i]=max(a[i].a1,a[i].a2);
			maxn[i]=max(maxn[i],a[i].a3);
			 m+=maxn[i];	
		}
		dan[j]=m;
		}
		else{
		for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(a[i].a2==0&&a[i].a3==0){
			m+=a[i].a1;
		}
		else{
		maxn[i]=max(a[i].a1,a[i].a2);
			maxn[i]=max(maxn[i],a[i].a3);
			 m+=maxn[i];	
		}
				
		}	
		dan[j]=m;	
			
		}
		
		
		}
		for(int i=1;i<=t;i++){
		cout<<dan[i]<<endl;	
		}
/*else{
		for(int j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			maxn[j]=max(a[j].a1,a[j].a2);
			maxn[j]=max(maxn[j],a[j].a3);
			if(maxn[j]==a[j].a1){
				maxs[j]=1;
				if(a[j].a2>a[j].a3){
				maxn2[j]=a[j].a2;
				maxs2[j]=2;	
				}
				else {
					maxn2[j]=a[j].a3;
					maxs2[j]=3;
				}
			}
			else if(maxn[j]==a[j].a2){
				maxs[j]=2;
				if(a[j].a1>a[j].a3){
				maxn2[j]=a[j].a1;
				maxs2[j]=1;	
				}
				else {
					maxn2[j]=a[j].a3;
					maxs2[j]=3;
				}
			}
			else if(maxn[j]==a[j].a3){
				maxs[j]=3;
				if(a[j].a2>a[j].a3){
				maxn2[j]=a[j].a2;
				maxs2[j]=2;	
				}
				else {
					maxn2[j]=a[j].a3;
					maxs2[j]=3;
				}
			}
///////////////////////////////////////////////////////É¾×¢ÊÍ£¡£¡£¡
				t1[j]=maxn[j];
				s1[j]=maxs[j];
			
		}
		for(int g=1;g<=n;g++){
			if(s1[g]==1){
			if(a1s<=n/2){
			a1s++;
			ans+=t1[g]; 
		}
		else{
			if(maxs2[g]==2){
			if(a2s<=n/2){
			a2s++;
			ans+=maxn2[g]; 
		}	
		else{
		if(maxs2[g]==3){
			if(a3s<=n/2){
			a3s++;
			ans+=maxn2[g]; 
		}	
			}
			else{
			if(maxs2[g]==1){
			if(a1s<=n/2){
			a1s++;
			ans+=maxn2[g]; 
		}	
			}		
		}
			}
		}
			}
		 if(s1[g]==2){
			if(a2s<=n/2){
			a2s++;
			ans+=t1[g];	
			}
			else{
			if(maxs2[g]==3){
			if(a3s<=n/2){
			a3s++;
			ans+=maxn2[g]; 
		}	
		}
		else{
		if(maxs2[g]==2){
			if(a2s<=n/2){
			a2s++;
			ans+=maxn2[g]; 
		}	
			}
			else{
			if(maxs2[g]==1){
			if(a1s<=n/2){
			a1s++;
			ans+=maxn2[g]; 
		}	
			}	
			}
		}
				
			}
			 
		}
		 if(maxs2[g]!=1&&maxs2[g]!=2&&a3s<=n/2){
			a3s++;
			ans+=t1[g]; 
		}
		else{
		if(maxs2[g]==2){
			if(a2s<=n/2){
			a2s++;
			ans+=maxn2[g]; 
		}	
			}	
			else{
			if(maxs2[g]==1){
			if(a1s<=n/2){
			a1s++;
			ans+=maxn2[g]; 
		}	
			}
			else{
				if(maxs2[g]==3){
			if(a3s<=n/2){
			a3s++;
			ans+=maxn2[g]; 
		}
			}
			}	
			}
		}				
		}
					
		
	
			
		}
		
		dan[i]=ans;
}
		
		
		
		
			
	}
	 for(int i=1;i<=n;i++){
	 	cout<<dan[i]<<endl;
	 } */
	return 0;
}
