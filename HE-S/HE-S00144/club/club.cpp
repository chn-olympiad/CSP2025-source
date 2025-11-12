#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int a2[100010];
	cin>>t;
	while(t>0){
		t--;
		int sum=0;
		int x,y;
		cin>>n;
		for(int i=1;i<=n;i++){
			
			
			cin>>a2[i];
			cin>>x;
			cin>>y;
		}
		int f[100100][4];
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				if(a2[j]<a2[j+1]) swap(a2[j],a2[j+1]);
			}	
		}
		for(int i=1;i<=n/2;i++){
			sum+=a2[i];
		}	
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
