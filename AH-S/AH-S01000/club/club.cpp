#include<bits/stdc++.h>
using namespace std;
int s[100005][4];
int a1[100005];
int a2[100005];
int a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int n;
		cin>>n;
		int s1=0,s2=0,s3=0;
		int sum=0;
		for (int j=0;j<n;j++){
			for (int z=0;z<3;z++){
				cin>>s[j][z]; 
			}
		}
		for (int j=0;j<n;j++){
			if (s[j][0]>=s[j][1] && s[j][0]>=s[j][2]){
				if (s1<=n/2){
					s1+=1;
					a1[j]=s[j][0];
				}
				else if(s[j][1]>=s[j][2]){
					if (s2<=n/2){
						s2+=1;
						a2[j]=s[j][1];
					}
				}
				else if(s[j][2]>s[j][1]){
					if (s3<=n/2){
					s3+=1;
					a3[j]=s[j][2];
				}
				}
				else {
					sort(a1,a1+n);
					for (int z=0;z<j;z++){
						if (s[j][0]>a1[z] && a1[z]>0){
							a1[z]=s[j][0];
							break;
						}
					}
				}
			}
			else if (s[j][1]>=s[j][2] && s[j][1]>=s[j][0]){
				if (s2<=n/2){
					s2+=1;
					a2[j]=s[j][1];
				}
				else if(s[j][2]>=s[j][0]){
					if (s3<=n/2){
						s3+=1;
						a3[j]=s[j][2];
					}
				}
				else if(s[j][0]>s[j][2]){
					if (s1<=n/2){
						s1+=1;
						a1[j]=s[j][0];
					}
				}
				else {
					sort(a2,a2+n);
					for (int z=0;z<j;z++){
						if (s[j][1]>a2[z] && a2[z]>0){
							a2[z]=s[j][1];
							break;
						}
					}
				}
			}
			else{
				if (s3<=n/2){
					s3+=1;
					a3[j]=s[j][2];
				}
				else if(s[j][0]>=s[j][1]){
					if (s1<=n/2){
						s1+=1;
						a1[j]=s[j][0];
					}
				}
				else if(s[j][1]>s[j][0]){
					if (s2<=n/2){
					s2+=1;
					a2[j]=s[j][1];
				}
				}
				else {
					sort(a3,a3+n);
					for (int z=0;z<j;z++){
						if (s[j][2]>a3[z] && a3[z]>0){
							a3[z]=s[j][2];
							break;
						}
						
					}
				}
			}
		}
		for (int i=0;i<n;i++){
			if (a1[i]>0) sum+=a1[i];
			else if (a2[i]>0) sum+=a2[i];
			else if (a3[i]>0) sum+=a3[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
