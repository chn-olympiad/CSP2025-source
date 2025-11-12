#include<bits/stdc++.h>
using namespace std;
struct a{
	int af[3];
}a[10001];
int max(int x,int y,int z){
	if(x>y){
		if(y>z)
			return x;
		else{
			if(x>z)
				return x;
			else
				return z;
		}
	}
	else{
		if(x>z)
			return y;
		else{
			if(y>z)
				return y;
			else
				return z;
		}
	}
}
int maxpuss(int x,int y,int z){
	if(x>y){
		if(y>z)
			return y;
		else{
			if(x>z)
				return z;
			else
				return y;
		}
	}
	else{
		if(x>z)
			return x;
		else{
			if(y>z)
				return z;
			else
				return x;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,zg[6];
	cin>>t;
	for(int x=1;x<=t;x++){
		int n,a1=0,a2=0,a3=0,maxi[3],maxj[10001];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].af[1]>>a[i].af[2]>>a[i].af[3];
			if(a[i].af[1]>maxi[1])
				maxi[1]=a[i].af[1];
			if(a[i].af[2]>maxi[2])
				maxi[2]=a[i].af[2];
			if(a[i].af[3]>maxi[3])
				maxi[3]=a[i].af[3];
			maxj[i]=max(a[i].af[1],a[i].af[2],a[i].af[3]);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(maxj[i]>maxi[j]){
					sum+=maxj[i];
					break;
				}
				else{
					if(maxj[i]<maxi[j]){
						sum+=maxi[j];
						break;
					}
					else{
						sum+=maxj[i];
						break;
					}
				}
			}
		}
		cout<<sum-2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
