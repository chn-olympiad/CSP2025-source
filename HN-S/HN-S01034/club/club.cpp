#include<bits/stdc++.h>
using namespace std;
int x[100005][5],v[50005][5];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout)
	int t;
	cin>>t;
	while(t--){
		int n,a=0,b=0,c=0,zh=0,s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i][1]>>x[i][2]>>x[i][3];
			if(x[i][1]>=x[i][2] and x[i][1]>=x[i][3])x[i][4]=1,a++,zh+=x[i][1];
			else if(x[i][2]>=x[i][1] and x[i][2]>=x[i][3])x[i][4]=2,b++,zh+=x[i][2];
			else if(x[i][3]>=x[i][2] and x[i][3]>=x[i][1])x[i][4]=3,c++,zh+=x[i][3];
		}
		if(a>n/2){
			int a1=a-n/2;
			if(a1*a1<n){
				for(int i=1;i<=a1;i++){
					if(x[i][4]==1){
						if(x[i][2]>=x[i][3]){
							zh=zh-x[i][1]+x[i][2];
							x[i][4]=2;
							a--;
							b++;
						}
						else{
							zh=zh-x[i][1]+x[i][3];
							x[i][4]=3;
							a--;
							b++;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(x[i][4]==1)s++,v[s][1]=x[i][1],v[s][2]=x[i][2],v[s][3]=x[i][3],v[s][4]=x[i][4],v[s][5]=v[s][1]-max(v[s][2],v[s][3]);
				}
				for(int i=1;i<=s;i++){
					for(int j=1;j<=s-i+1;j++){
						if(v[j][5]>v[j+1][5]){
							int a1=v[j][1],b1=v[j][2],c1=v[j][3],d1=v[j][4],e1=v[j][5];
							v[j][1]=v[j+1][1];
							v[j][2]=v[j+1][2];
							v[j][3]=v[j+1][3];
							v[j][4]=v[j+1][4];
							v[j][5]=v[j+1][5];
							v[j+1][1]=a1;
							v[j+1][2]=b1;
							v[j+1][3]=c1;
							v[j+1][4]=d1;
							v[j+1][5]=e1;
						}
					}
				}
				for(int i=1;i<=a-n/2;i++){
					zh=zh-v[i][5];
				}
			}
		}
		if(b>n/2){
			int a1=b-n/2;
			if(a1*a1<n){
				for(int i=1;i<=a1;i++){
					if(x[i][4]==2){
						if(x[i][1]>=x[i][3]){
							zh=zh-x[i][2]+x[i][1];
							x[i][4]=1;
							b--;
							a++;
						}
						else{
							zh=zh-x[i][2]+x[i][3];
							x[i][4]=3;
							b--;
							c++;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(x[i][4]==2)s++,v[s][1]=x[i][1],v[s][2]=x[i][2],v[s][3]=x[i][3],v[s][4]=x[i][4],v[s][5]=v[s][2]-max(v[s][1],v[s][3]);
				}
				for(int i=1;i<=s;i++){
					for(int j=1;j<=s-i ;j++){
						if(v[j][5]>v[j+1][5]){
							int a1=v[j][1],b1=v[j][2],c1=v[j][3],d1=v[j][4],e1=v[j][5];
							v[j][1]=v[j+1][1];
							v[j][2]=v[j+1][2];
							v[j][3]=v[j+1][3];
							v[j][4]=v[j+1][4];
							v[j][5]=v[j+1][5];
							v[j+1][1]=a1;
							v[j+1][2]=b1;
							v[j+1][3]=c1;
							v[j+1][4]=d1;
							v[j+1][5]=e1;
						}
					}
				}
				for(int i=1;i<=b-n/2;i++){
					zh=zh-v[i][5];
				}
			}
		}
		if(c>n/2){
			int a1=c-n/2;
			if(a1*a1<n){
				for(int i=1;i<=a1;i++){
					if(x[i][4]==3){
						if(x[i][2]>=x[i][1]){
							zh=zh-x[i][3]+x[i][2];
							x[i][4]=2;
							c--;
							b++;
						}
						else{
							zh=zh-x[i][1]+x[i][3];
							x[i][4]=1;
							c--;
							a++;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(x[i][4]==3)s++,v[s][1]=x[i][1],v[s][2]=x[i][2],v[s][3]=x[i][3],v[s][4]=x[i][4],v[s][5]=v[s][3]-max(v[s][2],v[s][1]);
				}
				for(int i=1;i<=s;i++){
					for(int j=1;j<=s-i+1;j++){
						if(v[j][5]>v[j+1][5]){
							int a1=v[j][1],b1=v[j][2],c1=v[j][3],d1=v[j][4],e1=v[j][5];
							v[j][1]=v[j+1][1];
							v[j][2]=v[j+1][2];
							v[j][3]=v[j+1][3];
							v[j][4]=v[j+1][4];
							v[j][5]=v[j+1][5];
							v[j+1][1]=a1;
							v[j+1][2]=b1;
							v[j+1][3]=c1;
							v[j+1][4]=d1;
							v[j+1][5]=e1;
						}
					}
				}
				for(int i=1;i<=c-n/2;i++){
					zh=zh-v[i][5];
				}
			}
		}
		cout<<zh<<endl;
	}
	return 0;
} 
