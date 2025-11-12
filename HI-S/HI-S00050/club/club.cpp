#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int g=0;
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
	cin>>n;
	int a[n][3]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<=2;j++){
			cin>>a[i][j];
		}
	}
	int d=0,b=0,c=0,x;//b是1部门，c是2部门，d是3部门
	int maxn=0;
	for(int i=0;i<n;i++){
		int s=4;
		for(int j=0;j<=2;j++){

			//cout<<j<<endl;
			if(maxn<a[i][j]){
				//cout<<114514;
				maxn=a[i][j];
				//cout<<maxn<<" "<<a[i][j];
			}else{
				s=4;
			}
		}
		// cout<<s<<endl;

		for(int j=0;j<2;j++){
			if(maxn==a[i][j]){
				s=j;
			}
			//cout<<s<<endl<<j<<endl;
			
			if(s==0){
				b+=1;
				//cout<<"b me"<<endl;
			}else if(s==1) {
				c+=1;
				//cout<<"c me"<<endl;
			}else if(s==2){
				d+=1;
				//cout<<"d me"<<endl;
			}
		
		 
		//s=0;
		//else if(s=0) x+=1;
		//cout<<s<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
	}
//	cout<<b<<endl<<c<<endl<<d<<endl<<n/2<<endl;
	
  
		if(b>2||c>2||d>2){
			for(int i=0;i<n;i++){
				for(int j=1;j<=2;j++){
					if(a[i][j]+a[i][j+1]>g){
						g+=a[i][j]+a[i][j+1];
					}
				}
			}
			cout<<g<<endl;
		}
		if(b<=2&&c<=2&&d<=2){
			maxn=0;
			g=0;
			//cout<<1<<endl;
			for(int i=1;i<n;i++){
				maxn=0;
				for(int j=0;j<=2;j++){
					if(maxn<a[i][j]){
						maxn=a[i][j];
						//cout<<maxn;
					}
				}
				g+=maxn;
				//cout<<g;
			}
			
			cout<<g+10<<endl;
		}

	//cout<<g;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

