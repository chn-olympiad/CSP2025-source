#include<bits/stdc++.h>
using namespace std;
int t;
int a[1000006][4];
int m=0;
int j=0;
int b=0;
int b1=0;
int b2=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int o=1;o<=3;i++) 
			cin>>a[i][o];
		}
		for(int i=1;i<=n;i++){
			m=n/2;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(b==m){
					if(a[i][2]>a[i][3]){
						if(b1==m){
							j+=a[i][3];
							b2+=1;
						}
						if(b1<m){
							j+=a[i][2];
							b1+=1;
						}
					}else if(a[i][3]>a[i][2]){
						if(b2==m){
							j+=a[i][2];
							b1+=1;
						}
						if(b2<m){
							j+=a[i][3];
							b2+=1;
						}
					}
				}else{
					j+=a[i][1];
					b+=1;
				}
			}if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				if(b1==m){
					if(a[i][1]>a[i][3]){
						if(b==m){
							j+=a[i][3];
							b2+=1;
						}
						if(b<m){
							j+=a[i][1];
							b+=1;
						}
					}else if(a[i][3]>a[i][2]){
						if(b2==m){
							j+=a[i][1];
							b+=1;
						}
						if(b2<m){
							j+=a[i][3];
							b2+=1;
						}
					}
				}else{
					j+=a[i][2];
					b1+=1;
				}
			}if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				if(b2==m){
					if(a[i][2]>a[i][1]){
						if(b1==m){
							j+=a[i][1];
							b+=1;
						}
						if(b1<m){
							j+=a[i][2];
							b+=1;
						}
					}else if(a[i][1]>a[i][2]){
						if(b==m){
							j+=a[i][2];
							b+=1;
						}
						if(b<m){
							j+=a[i][1];
							b+=1;
						}
					}
				}else{
					j+=a[i][3];
					b2+=1;
				}
			}
			
		}
		cout<<j<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
