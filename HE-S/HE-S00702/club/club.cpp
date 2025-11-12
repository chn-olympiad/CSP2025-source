#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int max[10];
	for(int p=1;p<=t;p++){
		int n;
		cin>>n;
		int b=0,c=0,d=0;
		for(int o=1;o<=n;o++){
	int a[4];
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]>=a[2]&&a[1]>=a[3]){
			if(b+1<=n/2){
			b++;
			max[p]+=a[1];
			}
			else if(a[2]>=a[3]&&c+1<=n/2){
				c++;
				max[p]+=a[2];
			}
			else{
				d++;
				max[p]+=a[3];
			}

		}
		else if(a[2]>=a[1]&&a[2]>=a[3]){
			if(c+1<=n/2){
			c++;
			max[p]+=a[2];
			}
			else if(a[1]>=a[3]&&b+1<=n/2){
				b++;
				max[p]+=a[1];
			}
			else{
				d++;
				max[p]+=a[3];
			}

		}
		else if(a[3]>=a[1]&&a[3]>=a[2]){
			if(d+1<=n/2){
			d++;
			max[p]+=a[3];
			}
			else if(a[1]>=a[2]&&b+1<=n/2){
				b++;
				max[p]+=a[1];
			}
			else{
				c++;
				max[p]+=a[2];
			}

		}
		
}
}
for(int i=1;i<=t;i++){
	cout<<max[i]<<endl;
}
return 0;
}
