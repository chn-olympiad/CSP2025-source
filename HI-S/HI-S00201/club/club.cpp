#include<bits/stdc++.h>
using namespace std;
struct math{
	int A,B,C;
}a[100005];
int dp[100005]; 
bool ab(int x,int y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int  T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int c=1;c<=n;c++) cin>>a[c].A>>a[c].B>>a[c].C;
		vector<int>x,y,z;
		int a1=0,a2=0,a3=0,ans=0; 
		for(int c=1;c<=n;c++){
			if(a[c].A>=a[c].B&&a[c].A>=a[c].C){
			    a1++;
			    ans+=a[c].A;
				x.push_back(a[c].A-max(a[c].B,a[c].C));	
			}
			else if(a[c].B>=a[c].A&&a[c].B>=a[c].C){
				a2++;
				ans+=a[c].B; 
				y.push_back(a[c].B-max(a[c].A,a[c].C));
			}
			else{
			    a3++;
			    ans+=a[c].C;
			    z.push_back(a[c].C-max(a[c].B,a[c].A));
			}
		}
			if(a1<=n/2&&a2<=n/2&&a3<=n/2){
				cout<<ans;
				continue;
			}
			if(a1>n/2){
			    int z=a1-n/2;
			  	sort(x.begin(),x.end(),ab);
			  	for(int c=0;c<z;c++) ans-=x[c];
			}
			else if(a2>n/2){
			    int z=a2-n/2;
			  	sort(y.begin(),y.end(),ab);
			  	for(int c=0;c<z;c++) ans-=y[c];
			}
            else{
			    int l=a3-n/2;
			  	sort(z.begin(),z.end(),ab);
			  	for(int c=0;c<l;c++) ans-=z[c];
			}
			cout<<ans;
	}
	return 0;
}

