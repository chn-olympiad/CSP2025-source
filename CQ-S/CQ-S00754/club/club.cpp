#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.in","w",stdout);
	int t,ans[7];
	int n,a[100002][5],d[100002],p[5],c;
	for(int i=0;i<5;i++){
		p[i]=0;
	}
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ans[i]=0; 
		c=n/2;
		for(int j=0;j<n;j++){
			d[j]=0;
			for(int q=0;q<3;q++){
			cin>>a[j][q];
			d[j]=max(a[j][q],d[j]); 
		}
		}
		for(int j=0;j<n;j++){
			for(int q=0;q<3;q++){
			if(d[j]==a[j][q]){
				p[q]++;
			}
			if(p[q]>c){
				a[j][q]=0;
				p[q]--;
			}
		}
	}
		for(int j=0;j<n;j++){
			d[j]=0;
			for(int q=0;q<3;q++){
			d[j]=max(a[j][q],d[j]); 	
		}
}
        for(int j=0;j<n;j++){
		ans[i]+=d[j];
	}
		}
    for(int i=0;i<t;i++){
    	cout<<ans[i]<<endl;
	}
	return 0;
} 
