#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[5005]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0;
	cin>>n;
	bool flag=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>1){
			flag=1;
		}
		if(flag==0&&arr[i]==1){
			m++;
		}
	}
	if(!flag){
		int ans=1,tv=1;
		for(int i=m-1;i>=3;i--){
			ans+=tv*m;
			tv++;
		}
		cout<<ans;
		return 0;
	}else if(n==3){
		if(arr[0]+arr[1]+arr[2]>max(arr[0],max(arr[1],arr[2]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n<3){
		cout<<0;
	}else if(n==4){
		int js=0;
		if(arr[0]+arr[1]+arr[2]>max(arr[0],max(arr[1],arr[2]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]>max(arr[0],max(arr[1],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]>max(arr[0],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]>max(arr[1],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]>max(arr[0],max(arr[1],max(arr[2],arr[3])))*2){
			js++;
		}
		cout<<js;
		return 0;
	}else if(n==5){
		int js=0;
		if(arr[0]+arr[1]+arr[2]>max(arr[0],max(arr[1],arr[2]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]>max(arr[0],max(arr[1],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]>max(arr[0],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[4]>max(arr[0],max(arr[1],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[4]>max(arr[0],max(arr[2],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[3]+arr[4]>max(arr[0],max(arr[3],arr[4]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]>max(arr[1],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[4]>max(arr[1],max(arr[2],arr[4]))*2){
			js++;
		}
		if(arr[1]+arr[3]+arr[4]>max(arr[1],max(arr[3],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]>max(arr[0],max(arr[1],max(arr[2],arr[3])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[4]>max(arr[0],max(arr[1],max(arr[2],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]+arr[4]>max(arr[0],max(arr[1],max(arr[3],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]+arr[4]>max(arr[0],max(arr[2],max(arr[3],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]>max(arr[0],max(arr[1],max(arr[2],max(arr[3],arr[4]))))*2){
			js++;
		}
		cout<<js;
		return 0;
	}else if(n==6){
		int js=0;
		if(arr[0]+arr[1]+arr[2]>max(arr[0],max(arr[1],arr[2]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]>max(arr[0],max(arr[1],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[4]>max(arr[0],max(arr[1],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[5]>max(arr[0],max(arr[1],arr[5]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]>max(arr[0],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[4]>max(arr[0],max(arr[2],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[5]>max(arr[0],max(arr[2],arr[5]))*2){
			js++;
		}
		if(arr[0]+arr[3]+arr[4]>max(arr[0],max(arr[3],arr[4]))*2){
			js++;
		}
		if(arr[0]+arr[3]+arr[5]>max(arr[0],max(arr[3],arr[5]))*2){
			js++;
		}
		if(arr[0]+arr[4]+arr[5]>max(arr[0],max(arr[4],arr[5]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]>max(arr[1],max(arr[2],arr[3]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[4]>max(arr[1],max(arr[2],arr[4]))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[5]>max(arr[1],max(arr[2],arr[5]))*2){
			js++;
		}
		if(arr[1]+arr[3]+arr[4]>max(arr[1],max(arr[3],arr[4]))*2){
			js++;
		}
		if(arr[1]+arr[3]+arr[5]>max(arr[1],max(arr[3],arr[5]))*2){
			js++;
		}
		if(arr[1]+arr[4]+arr[5]>max(arr[1],max(arr[4],arr[5]))*2){
			js++;
		}
		if(arr[2]+arr[3]+arr[4]>max(arr[2],max(arr[3],arr[4]))*2){
			js++;
		}
		if(arr[2]+arr[3]+arr[5]>max(arr[2],max(arr[3],arr[5]))*2){
			js++;
		}
		if(arr[2]+arr[4]+arr[5]>max(arr[2],max(arr[4],arr[5]))*2){
			js++;
		}
		if(arr[3]+arr[4]+arr[5]>max(arr[3],max(arr[4],arr[5]))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]>max(arr[0],max(arr[1],max(arr[2],arr[3])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[4]>max(arr[0],max(arr[1],max(arr[2],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[5]>max(arr[0],max(arr[1],max(arr[2],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]+arr[4]>max(arr[0],max(arr[1],max(arr[3],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]+arr[5]>max(arr[0],max(arr[1],max(arr[3],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[4]+arr[5]>max(arr[0],max(arr[1],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]+arr[4]>max(arr[0],max(arr[2],max(arr[3],arr[4])))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]+arr[5]>max(arr[0],max(arr[2],max(arr[3],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[4]+arr[5]>max(arr[0],max(arr[2],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[3]+arr[4]+arr[5]>max(arr[0],max(arr[3],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]>max(arr[1],max(arr[2],max(arr[3],arr[4])))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[5]>max(arr[1],max(arr[2],max(arr[3],arr[5])))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[4]+arr[5]>max(arr[1],max(arr[2],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[1]+arr[3]+arr[4]+arr[5]>max(arr[1],max(arr[3],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[2]+arr[3]+arr[4]+arr[5]>max(arr[2],max(arr[3],max(arr[4],arr[5])))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]>max(arr[0],max(arr[1],max(arr[2],max(arr[3],arr[4]))))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]+arr[5]>max(arr[0],max(arr[1],max(arr[2],max(arr[3],arr[5]))))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[4]+arr[5]>max(arr[0],max(arr[1],max(arr[2],max(arr[4],arr[5]))))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[3]+arr[4]+arr[5]>max(arr[0],max(arr[1],max(arr[3],max(arr[4],arr[5]))))*2){
			js++;
		}
		if(arr[0]+arr[2]+arr[3]+arr[4]+arr[5]>max(arr[0],max(arr[2],max(arr[3],max(arr[4],arr[5]))))*2){
			js++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]>max(arr[1],max(arr[2],max(arr[3],max(arr[4],arr[5]))))*2){
			js++;
		}
		if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]>max(arr[0],max(arr[1],max(arr[2],max(arr[3],max(arr[4],arr[5])))))*2){
			js++;
		}
		cout<<js;
		return 0;
	}
	cout<<n;
	return 0;
}
