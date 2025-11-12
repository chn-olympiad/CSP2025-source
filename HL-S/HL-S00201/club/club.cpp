#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0,club[3]={0};
		bool flag=true;
		cin>>n;
		int maxrs=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0||a[i][2]!=0){
				flag=false;
				break;
			}
		}
		if(flag==true){
			int a1[100005];
			for(int i=1;i<=n;i++){
				a1[i]=a[i][0];
			}
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=maxrs;i++){
				sum+=a1[i];
			}
		}
		else{
			for(int i=1;i<=n;i++){
				int maxi=a[i][0],id=0;
				if(a[i][1]>maxi){
					maxi=a[i][1];
					id=1;
				}
				else if(a[i][2]>maxi){
					maxi=a[i][2];
					id=2;
				}
				club[i]++;
				sum+=maxi;
			}
			
		}
		cout<<sum<<endl; 
	}
	return 0;
}
