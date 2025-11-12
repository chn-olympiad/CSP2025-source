#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool a[100010];			//Did a person have job
int b[3];				//How many persons are in an apartment
struct A{
	int i,j,value;		//i:Person,j:Apartment
}arr[300010];
bool inline cmp(A a,A b){return a.value>b.value;}
bool end(){
	for(int i=0;i<n;i++){
		if(!a[i])return 0;
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				int a;
				cin>>a;
				arr[i*3+j]={i,j,a};
			}
		}
		sort(arr,arr+3*n,cmp);
		ans=0;
		for(int i=0;i<3*n;i++){
			if(end())break;
			if(a[arr[i].i])continue;
			if(b[arr[i].j]==n/2)continue;
			ans+=arr[i].value;
			a[arr[i].i]=1;
			b[arr[i].j]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
