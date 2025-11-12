#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[500001],y,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<3){
	  cout<<0;	
	  fclose(stdin);
	  fclose(stdout);
	  return 0;	
	}
	else {
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]!=1)
			 f=1;
		}
		if(k==0&&f==0){
			cout<<0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		for(int i=0;i<n;i+=f){
			y=a[i];
			f=1;
//			cout<<endl<<i<<":";
//			cout<<y<<" ";
		    if(a[i]==k){
//				cout<<"["<<i<<","<<i<<"]";
				f=1;
				ans++;
			}
			else{			
				for(int j=i+1;j<n;j++){				
					y=y^a[j];
//				    cout<<y<<" ";
					if(y==k){
//						cout<<"["<<i<<","<<j<<"]";
						ans++;
						i=j+1;
						f=0;
						break;
	         	   }
				}
			}
		} 
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
