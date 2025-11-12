#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,z=0,ox,oy,oz;
	int a[1005];
	cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		int b[n][3];
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>b[j][k];
			}
		}
		int x=0;
		for(int j=0;j<n;){
			for(int k=0;k<3;k++){
				if(k==2){
					z+=x;
					//for(int f=0;f<3;f++){
						//if(x==b[j][f]&&f==0){
							//ox++;
						//}
						//if(x==b[j][f]&&f==1){
							//oy++;
						//}
						//if(x==b[j][f]&&f==2){
							///oz++;
						//}
					//}
					j++;
					break;
				}
				x=b[j][k];
				if(x<=b[j][k+1]){
					x=b[j][k+1];
				}
			}
		}
		//if(ox<n/2||oy<n/2||oz<n/2){
			a[i]=z;
			z=0;
		//}
		//else{
			//int p=max(ox,oy,oz);
			//int q=min(ox,oy,oz);
			//int o=ox+oy+oz-p-q;
			//a[i]=z;
		//}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
